namespace RemoteFlightController
{
    partial class frmRemoteFlightController
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmRemoteFlightController));
            this.grpPlane = new System.Windows.Forms.GroupBox();
            this.txtElevatorPitch = new System.Windows.Forms.TextBox();
            this.txtThrottle = new System.Windows.Forms.TextBox();
            this.txtAltitude = new System.Windows.Forms.TextBox();
            this.txtPitchAngle = new System.Windows.Forms.TextBox();
            this.txtAirspeed = new System.Windows.Forms.TextBox();
            this.lblElevatorPitch = new System.Windows.Forms.Label();
            this.txtVerticalSpeed = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.lblThrottle = new System.Windows.Forms.Label();
            this.lblPitchAngle = new System.Windows.Forms.Label();
            this.lblAirspeed = new System.Windows.Forms.Label();
            this.grpDataTable = new System.Windows.Forms.GroupBox();
            this.dgvRecievedData = new System.Windows.Forms.DataGridView();
            this.clnSpeed = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.clnVerticalSpeed = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.clnPitch = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.clnAltitude = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.clnThrottle = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.clnElevatorPitch = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.clnWarningCode = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.lblCurrentConnection = new System.Windows.Forms.Label();
            this.grpConnectionDetails = new System.Windows.Forms.GroupBox();
            this.btnConnect = new System.Windows.Forms.Button();
            this.txtPort = new System.Windows.Forms.TextBox();
            this.txtIpAddress = new System.Windows.Forms.TextBox();
            this.lblPort = new System.Windows.Forms.Label();
            this.lblIpAddress = new System.Windows.Forms.Label();
            this.lblTitle = new System.Windows.Forms.Label();
            this.grpWarning = new System.Windows.Forms.GroupBox();
            this.lblWarning = new System.Windows.Forms.Label();
            this.trkThrottle = new System.Windows.Forms.TrackBar();
            this.grpControl = new System.Windows.Forms.GroupBox();
            this.lblThrottleMin = new System.Windows.Forms.Label();
            this.lblThrottleMax = new System.Windows.Forms.Label();
            this.lblElevatorPitchMin = new System.Windows.Forms.Label();
            this.lblElevatorPitchMax = new System.Windows.Forms.Label();
            this.grpElevatorPitchCurrent = new System.Windows.Forms.GroupBox();
            this.lblCurrentElevatorPitch = new System.Windows.Forms.Label();
            this.grpThrottleCurrent = new System.Windows.Forms.GroupBox();
            this.lblCurrentThrottle = new System.Windows.Forms.Label();
            this.lblControlsThrottle = new System.Windows.Forms.Label();
            this.lblControlsElevatorPitch = new System.Windows.Forms.Label();
            this.trkElevatorPitch = new System.Windows.Forms.TrackBar();
            this.btnExit = new System.Windows.Forms.Button();
            this.grpPlane.SuspendLayout();
            this.grpDataTable.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvRecievedData)).BeginInit();
            this.grpConnectionDetails.SuspendLayout();
            this.grpWarning.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trkThrottle)).BeginInit();
            this.grpControl.SuspendLayout();
            this.grpElevatorPitchCurrent.SuspendLayout();
            this.grpThrottleCurrent.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trkElevatorPitch)).BeginInit();
            this.SuspendLayout();
            // 
            // grpPlane
            // 
            this.grpPlane.Controls.Add(this.txtElevatorPitch);
            this.grpPlane.Controls.Add(this.txtThrottle);
            this.grpPlane.Controls.Add(this.txtAltitude);
            this.grpPlane.Controls.Add(this.txtPitchAngle);
            this.grpPlane.Controls.Add(this.txtAirspeed);
            this.grpPlane.Controls.Add(this.lblElevatorPitch);
            this.grpPlane.Controls.Add(this.txtVerticalSpeed);
            this.grpPlane.Controls.Add(this.label8);
            this.grpPlane.Controls.Add(this.label7);
            this.grpPlane.Controls.Add(this.lblThrottle);
            this.grpPlane.Controls.Add(this.lblPitchAngle);
            this.grpPlane.Controls.Add(this.lblAirspeed);
            this.grpPlane.Location = new System.Drawing.Point(12, 459);
            this.grpPlane.Name = "grpPlane";
            this.grpPlane.Size = new System.Drawing.Size(591, 105);
            this.grpPlane.TabIndex = 8;
            this.grpPlane.TabStop = false;
            this.grpPlane.Text = "Plane";
            // 
            // txtElevatorPitch
            // 
            this.txtElevatorPitch.Location = new System.Drawing.Point(375, 72);
            this.txtElevatorPitch.Name = "txtElevatorPitch";
            this.txtElevatorPitch.ReadOnly = true;
            this.txtElevatorPitch.Size = new System.Drawing.Size(204, 20);
            this.txtElevatorPitch.TabIndex = 14;
            // 
            // txtThrottle
            // 
            this.txtThrottle.Location = new System.Drawing.Point(85, 73);
            this.txtThrottle.Name = "txtThrottle";
            this.txtThrottle.ReadOnly = true;
            this.txtThrottle.Size = new System.Drawing.Size(204, 20);
            this.txtThrottle.TabIndex = 13;
            // 
            // txtAltitude
            // 
            this.txtAltitude.Location = new System.Drawing.Point(375, 47);
            this.txtAltitude.Name = "txtAltitude";
            this.txtAltitude.ReadOnly = true;
            this.txtAltitude.Size = new System.Drawing.Size(204, 20);
            this.txtAltitude.TabIndex = 12;
            // 
            // txtPitchAngle
            // 
            this.txtPitchAngle.Location = new System.Drawing.Point(85, 47);
            this.txtPitchAngle.Name = "txtPitchAngle";
            this.txtPitchAngle.ReadOnly = true;
            this.txtPitchAngle.Size = new System.Drawing.Size(204, 20);
            this.txtPitchAngle.TabIndex = 11;
            // 
            // txtAirspeed
            // 
            this.txtAirspeed.Location = new System.Drawing.Point(85, 21);
            this.txtAirspeed.Name = "txtAirspeed";
            this.txtAirspeed.ReadOnly = true;
            this.txtAirspeed.Size = new System.Drawing.Size(204, 20);
            this.txtAirspeed.TabIndex = 9;
            // 
            // lblElevatorPitch
            // 
            this.lblElevatorPitch.AutoSize = true;
            this.lblElevatorPitch.Location = new System.Drawing.Point(297, 76);
            this.lblElevatorPitch.Name = "lblElevatorPitch";
            this.lblElevatorPitch.Size = new System.Drawing.Size(72, 13);
            this.lblElevatorPitch.TabIndex = 8;
            this.lblElevatorPitch.Text = "Elevator pitch";
            // 
            // txtVerticalSpeed
            // 
            this.txtVerticalSpeed.Location = new System.Drawing.Point(375, 21);
            this.txtVerticalSpeed.Name = "txtVerticalSpeed";
            this.txtVerticalSpeed.ReadOnly = true;
            this.txtVerticalSpeed.Size = new System.Drawing.Size(204, 20);
            this.txtVerticalSpeed.TabIndex = 10;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(313, 50);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(42, 13);
            this.label8.TabIndex = 7;
            this.label8.Text = "Altitude";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(295, 24);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(74, 13);
            this.label7.TabIndex = 6;
            this.label7.Text = "Vertical speed";
            // 
            // lblThrottle
            // 
            this.lblThrottle.AutoSize = true;
            this.lblThrottle.Location = new System.Drawing.Point(27, 76);
            this.lblThrottle.Name = "lblThrottle";
            this.lblThrottle.Size = new System.Drawing.Size(43, 13);
            this.lblThrottle.TabIndex = 5;
            this.lblThrottle.Text = "Throttle";
            // 
            // lblPitchAngle
            // 
            this.lblPitchAngle.AutoSize = true;
            this.lblPitchAngle.Location = new System.Drawing.Point(22, 50);
            this.lblPitchAngle.Name = "lblPitchAngle";
            this.lblPitchAngle.Size = new System.Drawing.Size(60, 13);
            this.lblPitchAngle.TabIndex = 4;
            this.lblPitchAngle.Text = "Pitch angle";
            // 
            // lblAirspeed
            // 
            this.lblAirspeed.AutoSize = true;
            this.lblAirspeed.Location = new System.Drawing.Point(27, 24);
            this.lblAirspeed.Name = "lblAirspeed";
            this.lblAirspeed.Size = new System.Drawing.Size(48, 13);
            this.lblAirspeed.TabIndex = 3;
            this.lblAirspeed.Text = "Airspeed";
            // 
            // grpDataTable
            // 
            this.grpDataTable.Controls.Add(this.dgvRecievedData);
            this.grpDataTable.Location = new System.Drawing.Point(12, 162);
            this.grpDataTable.Name = "grpDataTable";
            this.grpDataTable.Size = new System.Drawing.Size(591, 237);
            this.grpDataTable.TabIndex = 7;
            this.grpDataTable.TabStop = false;
            this.grpDataTable.Text = "Recieved data table";
            // 
            // dgvRecievedData
            // 
            this.dgvRecievedData.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvRecievedData.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.clnSpeed,
            this.clnVerticalSpeed,
            this.clnPitch,
            this.clnAltitude,
            this.clnThrottle,
            this.clnElevatorPitch,
            this.clnWarningCode});
            this.dgvRecievedData.Location = new System.Drawing.Point(17, 20);
            this.dgvRecievedData.Name = "dgvRecievedData";
            this.dgvRecievedData.Size = new System.Drawing.Size(562, 217);
            this.dgvRecievedData.TabIndex = 0;
            // 
            // clnSpeed
            // 
            this.clnSpeed.HeaderText = "Speed";
            this.clnSpeed.Name = "clnSpeed";
            this.clnSpeed.ReadOnly = true;
            this.clnSpeed.Width = 85;
            // 
            // clnVerticalSpeed
            // 
            this.clnVerticalSpeed.HeaderText = "Vertical Speed";
            this.clnVerticalSpeed.Name = "clnVerticalSpeed";
            this.clnVerticalSpeed.ReadOnly = true;
            this.clnVerticalSpeed.Width = 80;
            // 
            // clnPitch
            // 
            this.clnPitch.HeaderText = "Pitch angle";
            this.clnPitch.Name = "clnPitch";
            this.clnPitch.Width = 80;
            // 
            // clnAltitude
            // 
            this.clnAltitude.HeaderText = "Altitude";
            this.clnAltitude.Name = "clnAltitude";
            this.clnAltitude.ReadOnly = true;
            this.clnAltitude.Width = 80;
            // 
            // clnThrottle
            // 
            this.clnThrottle.HeaderText = "Throttle";
            this.clnThrottle.Name = "clnThrottle";
            this.clnThrottle.ReadOnly = true;
            this.clnThrottle.Width = 70;
            // 
            // clnElevatorPitch
            // 
            this.clnElevatorPitch.HeaderText = "Elevator pitch";
            this.clnElevatorPitch.Name = "clnElevatorPitch";
            this.clnElevatorPitch.ReadOnly = true;
            this.clnElevatorPitch.Width = 70;
            // 
            // clnWarningCode
            // 
            this.clnWarningCode.HeaderText = "Warning Code";
            this.clnWarningCode.Name = "clnWarningCode";
            this.clnWarningCode.ReadOnly = true;
            this.clnWarningCode.Width = 54;
            // 
            // lblCurrentConnection
            // 
            this.lblCurrentConnection.AutoSize = true;
            this.lblCurrentConnection.Location = new System.Drawing.Point(82, 22);
            this.lblCurrentConnection.Name = "lblCurrentConnection";
            this.lblCurrentConnection.Size = new System.Drawing.Size(109, 13);
            this.lblCurrentConnection.TabIndex = 6;
            this.lblCurrentConnection.Text = "<Current connection>";
            // 
            // grpConnectionDetails
            // 
            this.grpConnectionDetails.Controls.Add(this.btnConnect);
            this.grpConnectionDetails.Controls.Add(this.txtPort);
            this.grpConnectionDetails.Controls.Add(this.txtIpAddress);
            this.grpConnectionDetails.Controls.Add(this.lblPort);
            this.grpConnectionDetails.Controls.Add(this.lblIpAddress);
            this.grpConnectionDetails.Controls.Add(this.lblCurrentConnection);
            this.grpConnectionDetails.Location = new System.Drawing.Point(12, 54);
            this.grpConnectionDetails.Name = "grpConnectionDetails";
            this.grpConnectionDetails.Size = new System.Drawing.Size(355, 102);
            this.grpConnectionDetails.TabIndex = 5;
            this.grpConnectionDetails.TabStop = false;
            this.grpConnectionDetails.Text = "Connection Details";
            // 
            // btnConnect
            // 
            this.btnConnect.Location = new System.Drawing.Point(232, 45);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(107, 46);
            this.btnConnect.TabIndex = 4;
            this.btnConnect.Text = "Connect";
            this.btnConnect.UseVisualStyleBackColor = true;
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // txtPort
            // 
            this.txtPort.Location = new System.Drawing.Point(69, 71);
            this.txtPort.Name = "txtPort";
            this.txtPort.Size = new System.Drawing.Size(157, 20);
            this.txtPort.TabIndex = 3;
            // 
            // txtIpAddress
            // 
            this.txtIpAddress.Location = new System.Drawing.Point(69, 45);
            this.txtIpAddress.Name = "txtIpAddress";
            this.txtIpAddress.Size = new System.Drawing.Size(157, 20);
            this.txtIpAddress.TabIndex = 2;
            // 
            // lblPort
            // 
            this.lblPort.AutoSize = true;
            this.lblPort.Location = new System.Drawing.Point(22, 74);
            this.lblPort.Name = "lblPort";
            this.lblPort.Size = new System.Drawing.Size(26, 13);
            this.lblPort.TabIndex = 1;
            this.lblPort.Text = "Port";
            // 
            // lblIpAddress
            // 
            this.lblIpAddress.AutoSize = true;
            this.lblIpAddress.Location = new System.Drawing.Point(6, 48);
            this.lblIpAddress.Name = "lblIpAddress";
            this.lblIpAddress.Size = new System.Drawing.Size(57, 13);
            this.lblIpAddress.TabIndex = 0;
            this.lblIpAddress.Text = "IP address";
            // 
            // lblTitle
            // 
            this.lblTitle.AutoSize = true;
            this.lblTitle.Font = new System.Drawing.Font("Microsoft Sans Serif", 27.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTitle.Location = new System.Drawing.Point(90, 9);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(423, 42);
            this.lblTitle.TabIndex = 9;
            this.lblTitle.Text = "Remote flight controller";
            // 
            // grpWarning
            // 
            this.grpWarning.Controls.Add(this.lblWarning);
            this.grpWarning.Location = new System.Drawing.Point(12, 405);
            this.grpWarning.Name = "grpWarning";
            this.grpWarning.Size = new System.Drawing.Size(593, 48);
            this.grpWarning.TabIndex = 10;
            this.grpWarning.TabStop = false;
            this.grpWarning.Text = "Warning";
            // 
            // lblWarning
            // 
            this.lblWarning.AutoSize = true;
            this.lblWarning.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblWarning.Location = new System.Drawing.Point(16, 17);
            this.lblWarning.Name = "lblWarning";
            this.lblWarning.Size = new System.Drawing.Size(58, 16);
            this.lblWarning.TabIndex = 0;
            this.lblWarning.Text = "Warning";
            // 
            // trkThrottle
            // 
            this.trkThrottle.Enabled = false;
            this.trkThrottle.Location = new System.Drawing.Point(85, 46);
            this.trkThrottle.Maximum = 100;
            this.trkThrottle.Name = "trkThrottle";
            this.trkThrottle.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.trkThrottle.Size = new System.Drawing.Size(45, 211);
            this.trkThrottle.TabIndex = 11;
            this.trkThrottle.Scroll += new System.EventHandler(this.trkThrottle_Scroll);
            // 
            // grpControl
            // 
            this.grpControl.Controls.Add(this.lblThrottleMin);
            this.grpControl.Controls.Add(this.lblThrottleMax);
            this.grpControl.Controls.Add(this.lblElevatorPitchMin);
            this.grpControl.Controls.Add(this.lblElevatorPitchMax);
            this.grpControl.Controls.Add(this.grpElevatorPitchCurrent);
            this.grpControl.Controls.Add(this.grpThrottleCurrent);
            this.grpControl.Controls.Add(this.lblControlsThrottle);
            this.grpControl.Controls.Add(this.lblControlsElevatorPitch);
            this.grpControl.Controls.Add(this.trkElevatorPitch);
            this.grpControl.Controls.Add(this.trkThrottle);
            this.grpControl.Location = new System.Drawing.Point(12, 570);
            this.grpControl.Name = "grpControl";
            this.grpControl.Size = new System.Drawing.Size(289, 257);
            this.grpControl.TabIndex = 11;
            this.grpControl.TabStop = false;
            this.grpControl.Text = "Controls";
            // 
            // lblThrottleMin
            // 
            this.lblThrottleMin.AutoSize = true;
            this.lblThrottleMin.Location = new System.Drawing.Point(37, 230);
            this.lblThrottleMin.Name = "lblThrottleMin";
            this.lblThrottleMin.Size = new System.Drawing.Size(45, 13);
            this.lblThrottleMin.TabIndex = 21;
            this.lblThrottleMin.Text = "Min: 0.0";
            // 
            // lblThrottleMax
            // 
            this.lblThrottleMax.AutoSize = true;
            this.lblThrottleMax.Location = new System.Drawing.Point(22, 46);
            this.lblThrottleMax.Name = "lblThrottleMax";
            this.lblThrottleMax.Size = new System.Drawing.Size(60, 13);
            this.lblThrottleMax.TabIndex = 20;
            this.lblThrottleMax.Text = "Max: 100.0";
            // 
            // lblElevatorPitchMin
            // 
            this.lblElevatorPitchMin.AutoSize = true;
            this.lblElevatorPitchMin.Location = new System.Drawing.Point(178, 230);
            this.lblElevatorPitchMin.Name = "lblElevatorPitchMin";
            this.lblElevatorPitchMin.Size = new System.Drawing.Size(48, 13);
            this.lblElevatorPitchMin.TabIndex = 19;
            this.lblElevatorPitchMin.Text = "Min: -5.0";
            // 
            // lblElevatorPitchMax
            // 
            this.lblElevatorPitchMax.AutoSize = true;
            this.lblElevatorPitchMax.Location = new System.Drawing.Point(178, 46);
            this.lblElevatorPitchMax.Name = "lblElevatorPitchMax";
            this.lblElevatorPitchMax.Size = new System.Drawing.Size(48, 13);
            this.lblElevatorPitchMax.TabIndex = 18;
            this.lblElevatorPitchMax.Text = "Max: 5.0";
            // 
            // grpElevatorPitchCurrent
            // 
            this.grpElevatorPitchCurrent.Controls.Add(this.lblCurrentElevatorPitch);
            this.grpElevatorPitchCurrent.Location = new System.Drawing.Point(151, 109);
            this.grpElevatorPitchCurrent.Name = "grpElevatorPitchCurrent";
            this.grpElevatorPitchCurrent.Size = new System.Drawing.Size(75, 59);
            this.grpElevatorPitchCurrent.TabIndex = 17;
            this.grpElevatorPitchCurrent.TabStop = false;
            this.grpElevatorPitchCurrent.Text = "Current";
            // 
            // lblCurrentElevatorPitch
            // 
            this.lblCurrentElevatorPitch.AutoSize = true;
            this.lblCurrentElevatorPitch.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblCurrentElevatorPitch.Location = new System.Drawing.Point(7, 20);
            this.lblCurrentElevatorPitch.Name = "lblCurrentElevatorPitch";
            this.lblCurrentElevatorPitch.Size = new System.Drawing.Size(45, 25);
            this.lblCurrentElevatorPitch.TabIndex = 0;
            this.lblCurrentElevatorPitch.Text = "0.0";
            // 
            // grpThrottleCurrent
            // 
            this.grpThrottleCurrent.Controls.Add(this.lblCurrentThrottle);
            this.grpThrottleCurrent.Location = new System.Drawing.Point(9, 109);
            this.grpThrottleCurrent.Name = "grpThrottleCurrent";
            this.grpThrottleCurrent.Size = new System.Drawing.Size(75, 59);
            this.grpThrottleCurrent.TabIndex = 16;
            this.grpThrottleCurrent.TabStop = false;
            this.grpThrottleCurrent.Text = "Current";
            // 
            // lblCurrentThrottle
            // 
            this.lblCurrentThrottle.AutoSize = true;
            this.lblCurrentThrottle.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblCurrentThrottle.Location = new System.Drawing.Point(7, 20);
            this.lblCurrentThrottle.Name = "lblCurrentThrottle";
            this.lblCurrentThrottle.Size = new System.Drawing.Size(54, 24);
            this.lblCurrentThrottle.TabIndex = 0;
            this.lblCurrentThrottle.Text = "0.0%";
            // 
            // lblControlsThrottle
            // 
            this.lblControlsThrottle.AutoSize = true;
            this.lblControlsThrottle.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblControlsThrottle.Location = new System.Drawing.Point(40, 16);
            this.lblControlsThrottle.Name = "lblControlsThrottle";
            this.lblControlsThrottle.Size = new System.Drawing.Size(53, 16);
            this.lblControlsThrottle.TabIndex = 15;
            this.lblControlsThrottle.Text = "Throttle";
            // 
            // lblControlsElevatorPitch
            // 
            this.lblControlsElevatorPitch.AutoSize = true;
            this.lblControlsElevatorPitch.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblControlsElevatorPitch.Location = new System.Drawing.Point(165, 16);
            this.lblControlsElevatorPitch.Name = "lblControlsElevatorPitch";
            this.lblControlsElevatorPitch.Size = new System.Drawing.Size(89, 16);
            this.lblControlsElevatorPitch.TabIndex = 15;
            this.lblControlsElevatorPitch.Text = "Elevator pitch";
            // 
            // trkElevatorPitch
            // 
            this.trkElevatorPitch.Cursor = System.Windows.Forms.Cursors.Default;
            this.trkElevatorPitch.Enabled = false;
            this.trkElevatorPitch.Location = new System.Drawing.Point(238, 46);
            this.trkElevatorPitch.Maximum = 50;
            this.trkElevatorPitch.Minimum = -50;
            this.trkElevatorPitch.Name = "trkElevatorPitch";
            this.trkElevatorPitch.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.trkElevatorPitch.Size = new System.Drawing.Size(45, 211);
            this.trkElevatorPitch.TabIndex = 12;
            this.trkElevatorPitch.Scroll += new System.EventHandler(this.trkElevatorPitch_Scroll);
            // 
            // btnExit
            // 
            this.btnExit.Location = new System.Drawing.Point(528, 804);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(75, 23);
            this.btnExit.TabIndex = 12;
            this.btnExit.Text = "Exit";
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // frmRemoteFlightController
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(618, 839);
            this.Controls.Add(this.grpWarning);
            this.Controls.Add(this.btnExit);
            this.Controls.Add(this.grpControl);
            this.Controls.Add(this.lblTitle);
            this.Controls.Add(this.grpPlane);
            this.Controls.Add(this.grpDataTable);
            this.Controls.Add(this.grpConnectionDetails);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "frmRemoteFlightController";
            this.Text = "frmRemoteFlightController";
            this.Load += new System.EventHandler(this.frmRemoteFlightController_Load);
            this.grpPlane.ResumeLayout(false);
            this.grpPlane.PerformLayout();
            this.grpDataTable.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgvRecievedData)).EndInit();
            this.grpConnectionDetails.ResumeLayout(false);
            this.grpConnectionDetails.PerformLayout();
            this.grpWarning.ResumeLayout(false);
            this.grpWarning.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trkThrottle)).EndInit();
            this.grpControl.ResumeLayout(false);
            this.grpControl.PerformLayout();
            this.grpElevatorPitchCurrent.ResumeLayout(false);
            this.grpElevatorPitchCurrent.PerformLayout();
            this.grpThrottleCurrent.ResumeLayout(false);
            this.grpThrottleCurrent.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trkElevatorPitch)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox grpPlane;
        private System.Windows.Forms.TextBox txtElevatorPitch;
        private System.Windows.Forms.TextBox txtThrottle;
        private System.Windows.Forms.TextBox txtAltitude;
        private System.Windows.Forms.TextBox txtPitchAngle;
        private System.Windows.Forms.TextBox txtVerticalSpeed;
        private System.Windows.Forms.TextBox txtAirspeed;
        private System.Windows.Forms.Label lblElevatorPitch;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label lblThrottle;
        private System.Windows.Forms.Label lblPitchAngle;
        private System.Windows.Forms.Label lblAirspeed;
        private System.Windows.Forms.GroupBox grpDataTable;
        private System.Windows.Forms.Label lblCurrentConnection;
        private System.Windows.Forms.GroupBox grpConnectionDetails;
        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.TextBox txtPort;
        private System.Windows.Forms.Label lblPort;
        private System.Windows.Forms.Label lblIpAddress;
        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.GroupBox grpWarning;
        private System.Windows.Forms.TrackBar trkThrottle;
        private System.Windows.Forms.GroupBox grpControl;
        private System.Windows.Forms.Label lblControlsThrottle;
        private System.Windows.Forms.Label lblControlsElevatorPitch;
        private System.Windows.Forms.TrackBar trkElevatorPitch;
        private System.Windows.Forms.Label lblWarning;
        private System.Windows.Forms.GroupBox grpElevatorPitchCurrent;
        private System.Windows.Forms.GroupBox grpThrottleCurrent;
        private System.Windows.Forms.TextBox txtIpAddress;
        private System.Windows.Forms.Label lblThrottleMin;
        private System.Windows.Forms.Label lblThrottleMax;
        private System.Windows.Forms.Label lblElevatorPitchMin;
        private System.Windows.Forms.Label lblElevatorPitchMax;
        private System.Windows.Forms.Label lblCurrentElevatorPitch;
        private System.Windows.Forms.Label lblCurrentThrottle;
        private System.Windows.Forms.DataGridView dgvRecievedData;
        private System.Windows.Forms.Button btnExit;
        private System.Windows.Forms.DataGridViewTextBoxColumn clnSpeed;
        private System.Windows.Forms.DataGridViewTextBoxColumn clnVerticalSpeed;
        private System.Windows.Forms.DataGridViewTextBoxColumn clnPitch;
        private System.Windows.Forms.DataGridViewTextBoxColumn clnAltitude;
        private System.Windows.Forms.DataGridViewTextBoxColumn clnThrottle;
        private System.Windows.Forms.DataGridViewTextBoxColumn clnElevatorPitch;
        private System.Windows.Forms.DataGridViewTextBoxColumn clnWarningCode;
    }
}

