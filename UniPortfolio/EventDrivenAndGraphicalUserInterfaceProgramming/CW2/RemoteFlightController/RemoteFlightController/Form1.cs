using System;
using System.Text;
using System.Threading;
using System.Net;
using System.Net.Sockets;
using System.Web.Script.Serialization;
using System.Windows.Forms;

namespace RemoteFlightController
{
    public struct ControlsUpdate
    {
        public double Throttle;
        public double ElevatorPitch;
    }

    public struct TelemetryUpdate
    {
        public double Altitude;
        public double Speed;
        public double Pitch;
        public double VerticalSpeed;

        public double Throttle;
        public double ElevatorPitch;

        public int WarningCode;
    }

    public delegate void SendingDataHandler(ControlsUpdate controlsUpdate);
    public delegate void RecievedDataHandler(TelemetryUpdate telemetryUpdate);

    public partial class frmRemoteFlightController : Form
    {
        
        TcpClient Client = new TcpClient();
        DataReciever reciever = new DataReciever();
        DataSender Sender = new DataSender();

        public frmRemoteFlightController()
        {
            InitializeComponent();
            reciever.RecievingEvent += new RecievedDataHandler(getControlsUpdate);
            Sender.SendingEvent += new SendingDataHandler(setControlsUpdate);
        }

        private void frmRemoteFlightController_Load(object sender, EventArgs e)
        {
            lblCurrentConnection.Text = " ";
            lblWarning.Text = " ";
            trkThrottle.Minimum = 0;
            trkThrottle.Maximum = 100;
            trkThrottle.TickFrequency = 1;
            trkElevatorPitch.Minimum = -50;
            trkElevatorPitch.Maximum = 50;
            trkElevatorPitch.Enabled = false;
            trkThrottle.Enabled = false;
        }

        private void btnConnect_Click(object sender, EventArgs e)
        {
            int Port = int.Parse(txtPort.Text);
            IPAddress IP = IPAddress.Parse(txtIpAddress.Text);
            txtPort.Text = Convert.ToString(Port);

            try
            {
                Client.Connect(IP, Port);
                lblCurrentConnection.Text = " Connected to: " + IP.ToString();

                trkThrottle.Enabled = true;
                trkElevatorPitch.Enabled = true;
                btnConnect.Enabled = false;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                txtIpAddress.Focus();
            }

            Thread retrivingThread = new Thread(new ThreadStart(reciever.RetriveData));
            retrivingThread.Start();
            NetworkStream stream = Client.GetStream();
            DataReciever.stream = stream;

            MessageBox.Show("Connected to: " + txtIpAddress.Text);
        }

        private void trkElevatorPitch_Scroll(object sender, EventArgs e)
        {
            double elevatorPitchValue = (trkElevatorPitch.Value * 0.1) / trkElevatorPitch.TickFrequency;
            lblCurrentElevatorPitch.Text = elevatorPitchValue.ToString() + "%";
            ControlsScrollUpdate();
        }

        private void trkThrottle_Scroll(object sender, EventArgs e)
        {
            lblCurrentThrottle.Text = trkThrottle.Value.ToString() + ".0%";
            ControlsScrollUpdate();
        }
        private void btnExit_Click(object sender, EventArgs e)
        {
            frmRemoteFlightController.ActiveForm.Close();
        }

        private void frmRemoteFlightController_FormClosing(object sender, FormClosingEventArgs e)
        {

        }

        public class DataSender
        {
            public event SendingDataHandler SendingEvent;
            public NetworkStream stream;

            public void SendData(ControlsUpdate controlUpdate)
            {
                JavaScriptSerializer serializer = new JavaScriptSerializer();
                string deserializedData = serializer.Serialize(controlUpdate);

                byte[] rawData = Encoding.ASCII.GetBytes(deserializedData);
                stream.Write(rawData, 0, rawData.Length);

                SendingEvent?.Invoke(controlUpdate);
            }
        }

        public class DataReciever
        {
            public event RecievedDataHandler RecievingEvent;
            public static NetworkStream stream;

            private bool StartRetrieving = false;

            public void RetriveData()
            {
                TelemetryUpdate telemetryUpdate = new TelemetryUpdate();

                StartRetrieving = true;

                while (StartRetrieving)
                {
                    byte[] buffer = new byte[256];
                    int num_bytes = stream.Read(buffer, 0, 256);
                    string ToBeDeSerialized = Encoding.ASCII.GetString(buffer, 0, num_bytes);

                    JavaScriptSerializer serializer = new JavaScriptSerializer();
                    telemetryUpdate = serializer.Deserialize<TelemetryUpdate>(ToBeDeSerialized);

                    RecievingEvent?.Invoke(telemetryUpdate);
                }
            }
        }

        public void ControlsScrollUpdate()
        {
            NetworkStream stream = Client.GetStream();

            ControlsUpdate controlsUpdate = new ControlsUpdate();
            controlsUpdate.Throttle = trkThrottle.Value;

            controlsUpdate.ElevatorPitch = trkElevatorPitch.Value * 0.1;

            Sender.stream = stream;
            Sender.SendData(controlsUpdate);

            Thread.Sleep(0100);
        }

        private void setControlsUpdate(ControlsUpdate controlUpdate)
        {
            if (this.InvokeRequired)
            {
                this.Invoke(new SendingDataHandler(setControlsUpdate), new object[] { controlUpdate });
            }
            else
            {
                controlUpdate.Throttle = trkThrottle.Value;
                controlUpdate.ElevatorPitch = trkElevatorPitch.Value * 0.1;
            }
        }

        private void getControlsUpdate(TelemetryUpdate telemetryUpdate)
        {
            if (this.InvokeRequired)
            {
                this.Invoke(new RecievedDataHandler(getControlsUpdate), new object[] { telemetryUpdate });
            }
            else
            {
                txtAltitude.Text = Math.Round(telemetryUpdate.Altitude).ToString() + " ft";
                txtAirspeed.Text = Math.Round(telemetryUpdate.Speed).ToString() + " Knts";
                txtVerticalSpeed.Text = Math.Round(telemetryUpdate.VerticalSpeed).ToString() + " Fpm";
                txtThrottle.Text = telemetryUpdate.Throttle.ToString() + "%";
                txtPitchAngle.Text = Math.Round(telemetryUpdate.Pitch).ToString() + "°";
                txtElevatorPitch.Text = telemetryUpdate.ElevatorPitch.ToString() + "°";

                DataGridViewRow row = (DataGridViewRow)dgvRecievedData.Rows[0].Clone();
                row.Cells[0].Value = telemetryUpdate.Speed.ToString();
                row.Cells[1].Value = telemetryUpdate.VerticalSpeed.ToString();
                row.Cells[2].Value = telemetryUpdate.Pitch.ToString();
                row.Cells[3].Value = telemetryUpdate.Altitude.ToString();
                row.Cells[4].Value = telemetryUpdate.Throttle.ToString();
                row.Cells[5].Value = telemetryUpdate.ElevatorPitch.ToString();
                row.Cells[6].Value = telemetryUpdate.WarningCode.ToString();

                dgvRecievedData.Rows.Insert(0, row);

                if (dgvRecievedData.Rows.Count > 10)
                {
                    dgvRecievedData.Rows.RemoveAt(9);
                }

                if (telemetryUpdate.WarningCode == 1)
                {
                    lblWarning.Text = "Warning: Too low terrain";
                }
                else if (telemetryUpdate.WarningCode == 2)
                {
                    lblWarning.Text = "Warning: Stall risk";
                }
                else
                {
                    lblWarning.Text = "No warning";
                }
            }
        }
    }
}