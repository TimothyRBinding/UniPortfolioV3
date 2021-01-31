using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Number_list_manager
{
    public partial class frmNumberListManager : Form
    {
        public frmNumberListManager()
        {
            InitializeComponent();
        }

        private const int maxNumOfEntries = 30;
        private static int minValue = 1; 
        private static int maxValue = 100;
        private static int probe = 0;
        //min and max must have a space of 30 numbers between otherwise the 
        //programme won't be able to fill the list properly in the initialize

        private void frmNumberListManager_Load(object sender, EventArgs e)
        {
            txtInsertBox.KeyPress += NumberInputOnly_KeyPress;
            txtSearchBox.KeyPress += NumberInputOnly_KeyPress;
            picDragAndDropBin.AllowDrop = true;//Allows for drag drop later on the picture
            Updating(); //Updates the programme when it starts
        }

        private void NumberInputOnly_KeyPress(object sender, KeyPressEventArgs e)
        {
            txtInsertBox.MaxLength = 5;
            txtSearchBox.MaxLength = 5;

            if (!char.IsControl(e.KeyChar) && !char.IsDigit(e.KeyChar) &&
            (e.KeyChar != '.'))
            {
                e.Handled = true;
            }

            if ((e.KeyChar == '.') && ((sender as TextBox).Text.IndexOf('.') > -1))
            {
                e.Handled = true;
            }
        }

        private void btnInsert_Click(object sender, EventArgs e)
        {
            int numberOfEntries = lstIntegerValues.Items.Count;

            if (txtInsertBox.Text == null || txtInsertBox.Text == "") //Checks if the insert textbox is not empty
            {
                MessageBox.Show("Insert box is empty, please enter a number", "Warning");
            }
            else if (numberOfEntries < maxNumOfEntries) 
                //Checks to make sure the maximum numbers haven't been reached
            {
                int insertedValue = Convert.ToInt32(txtInsertBox.Text); //Coverting string to integer

                if (LinearSearch(insertedValue) == 0 || insertedValue == Convert.ToInt32(lstIntegerValues.Items[0])) 
                    //Checks using the linear search to make sure the number does not already exist in the list
                {
                    if (insertedValue >= minValue && insertedValue <= maxValue) 
                        //Checks to make sure the inserted value is within the list boundaries
                    {
                        if (this.optSorted.Checked)
                        {
                            BubbleSort(); //Sorts list into numerical order

                            lstIntegerValues.Items[Insert(insertedValue)] = txtInsertBox.Text;
                            //Sets the item in the insert textbox its numerical sorted postion
                        }
                        else if (this.optUnsorted.Checked)
                        {
                            lstIntegerValues.Items.Add(txtInsertBox.Text);
                        }
                    }
                    else
                    {
                        MessageBox.Show("Do not enter numbers that are not within the permitted limit of: " + maxNumOfEntries, "Warning");
                    }
                }
                else
                {
                    MessageBox.Show("Please do not enter duplicate numbers", "Warning");
                }
            }
            else
            {
                MessageBox.Show("Maximum number of values in the list reached", "Warning");
            }

            Updating();
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            int numOfEntries = lstIntegerValues.Items.Count;

            if (txtSearchBox.Text == null || txtSearchBox.Text == "") //Checks if the Search textbox is not empty
            {
                MessageBox.Show("Search box is empty, please enter a number", "Warning");
            }

            else
            {
                int searchValue = Convert.ToInt32(txtSearchBox.Text);  //Coverting string to integer

                if (this.optLinearSearch.Checked)
                {
                    if (LinearSearch(searchValue) != 0 || searchValue == Convert.ToInt32(lstIntegerValues.Items[0]))
                    //Checks if number is in the list using a linear search, it also checks if the value to be 
                    //search is the first value as the methods returns 0 to state that the number could not be found
                    {
                        MessageBox.Show("The number " + txtSearchBox.Text + " is at the index of: " + LinearSearch(searchValue) + " Probes: " + probe, "Search complete!");
                    }
                    else //Otherwise Show error message
                    {
                        MessageBox.Show("Could not find entry: " + txtSearchBox.Text + " Probes: " + probe, "Warning");
                    }
                }
                else if (this.optBinarySearch.Checked)
                {
                    BubbleSort();

                    if (BinarySearch(searchValue) != 0 || searchValue == Convert.ToInt32(lstIntegerValues.Items[0]))
                        //Checks if number is in the list using a binary search, it also checks if the value to be 
                        //search is the first value as the methods returns 0 to state that the number could not be found
                    {
                        MessageBox.Show("The number " + txtSearchBox.Text + " is at the index of: " + BinarySearch(searchValue) + " Probes: " + probe, "Search complete!");
                    }
                    else //Otherwise Show error message
                    {
                        MessageBox.Show("Could not find entry: " + txtSearchBox.Text + " Probes: " + probe, "Warning");
                    }
                }
            }

            Updating();
        }

        private void btnInitialise_Click(object sender, EventArgs e)
        {
            int numOfEntries = lstIntegerValues.Items.Count;

            Random rnd = new Random();

            while (numOfEntries < maxNumOfEntries) //Used to fill the list completely
            {
                int randomIntializeNumber = rnd.Next(minValue, maxValue); //Uses mid and max value to determine the lowest and highest number that can be created
                //It must be able to create atleast 30 and above otherwise the programme won't work

                if (numOfEntries > 0) //Checks if their are numbers in the list before attempting to search
                {
                    if (LinearSearch(randomIntializeNumber) == 0 || randomIntializeNumber == Convert.ToInt32(lstIntegerValues.Items[0])) //Checks for duplicates
                    {
                        if (optSorted.Checked == true)
                        {
                            lstIntegerValues.Items.Add(randomIntializeNumber);
                            BubbleSort();
                        }
                        else
                        {
                            lstIntegerValues.Items.Add(randomIntializeNumber);
                        }
                    }
                }
                else
                {
                    lstIntegerValues.Items.Add(randomIntializeNumber);
                }
                numOfEntries = lstIntegerValues.Items.Count; //Updates number of entries everytime the loop runs
            }

            Updating();
        }

        private void btnShuffle_Click(object sender, EventArgs e)
        {
            int numOfEntries = lstIntegerValues.Items.Count;

            Random rnd = new Random();

            while (numOfEntries > 1)
            {
                numOfEntries--;
                int randomShuffleIndex = rnd.Next(numOfEntries + 1);
                object value = lstIntegerValues.Items[randomShuffleIndex];
                lstIntegerValues.Items[randomShuffleIndex] = lstIntegerValues.Items[numOfEntries];
                lstIntegerValues.Items[numOfEntries] = value;
            }

            Updating();
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            int numOfEntries = lstIntegerValues.Items.Count;
            int lastEntry = lstIntegerValues.Items.Count - 1; //Gets the last entry in the list

            for (int i = 0; i <= numOfEntries; i++)
            {
                if ((lstIntegerValues.SelectedIndex != -1) && (lstIntegerValues.SelectedIndex < lstIntegerValues.Items.Count - 1))
                {
                    lstIntegerValues.Items.Insert(lstIntegerValues.SelectedIndex + 2, lstIntegerValues.Text); //adds same item below
                    lstIntegerValues.SelectedIndex = lstIntegerValues.SelectedIndex + 2; //Sets the new duplicate as the current item
                    lstIntegerValues.Items.RemoveAt(lstIntegerValues.SelectedIndex - 2); //Deletes the old item

                    if (lstIntegerValues.SelectedIndex == lastEntry) //Checks if the item is the current item
                    {
                        lstIntegerValues.Items.RemoveAt(lastEntry); //removes item
                    }
                }
            }

            Updating();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            lstIntegerValues.Items.Clear();

            Updating();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Are you sure you want to exit?", "Warning", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.No) { }
            else { frmNumberListManager.ActiveForm.Close(); }
        }

        private void Updating()
        {
            int numOfEntries = lstIntegerValues.Items.Count;

            lblIntegerCount.Text = numOfEntries.ToString();
            lblNumberOfEntriesPermitted.Text = maxNumOfEntries.ToString();

            if (numOfEntries > 0)
            {
                lblFirstEntry.Text = lstIntegerValues.Items[0].ToString();
                lblLastEntry.Text = lstIntegerValues.Items[numOfEntries - 1].ToString();
                lblMaximumValue.Text = maxValue.ToString();
                lblMinimumValue.Text = minValue.ToString();
            }
            else
            {
                lblFirstEntry.Text = "0";
                lblLastEntry.Text = "0";
            }

            if (numOfEntries == maxNumOfEntries)
            {
                btnInitialise.Enabled = false;
                btnInsert.Enabled = false;
                txtInsertBox.Enabled = false;
                optSorted.Enabled = false;
                optUnsorted.Enabled = false;
            }
            else
            {
                btnInitialise.Enabled = true;
                btnInsert.Enabled = true;
                txtInsertBox.Enabled = true;
                optSorted.Enabled = true;
                optUnsorted.Enabled = true;
            }

            if (numOfEntries < 1)
            {
                btnDelete.Enabled = false;
                btnClear.Enabled = false;
            }
            else
            {
                btnDelete.Enabled = true;
                btnClear.Enabled = true;
            }

            if (numOfEntries < 2)
            {
                btnShuffle.Enabled = false;
                btnSearch.Enabled = false;
                txtSearchBox.Enabled = false;
                optBinarySearch.Enabled = false;
                optLinearSearch.Enabled = false;
            }
            else
            {
                btnShuffle.Enabled = true;
                btnSearch.Enabled = true;
                txtSearchBox.Enabled = true;
                optBinarySearch.Enabled = true;
                optLinearSearch.Enabled = true;
            }
        }

        private int BinarySearch(int valueToBeSearched)
        {
            int numOfEntries = lstIntegerValues.Items.Count;
            probe = 0;

            if (numOfEntries <= 1)
            {
                return 0; //Stops the search if their is only one entry
            }

            int low = Convert.ToInt32(lstIntegerValues.Items[0]);
            int high = numOfEntries - 1;
            int middle = (low + high) / 2;

            while (low <= high)
            {
                int listIndex = lstIntegerValues.Items.IndexOf(valueToBeSearched);

                if (valueToBeSearched == Convert.ToInt32(lstIntegerValues.Items[middle])) 
                    //If the number in the middle is the number we are looking for then
                {
                    return listIndex; //Give us the index

                }
                else if (valueToBeSearched < Convert.ToInt32(lstIntegerValues.Items[middle])) 
                    //Otherwise check if the number is less than
                {
                    high = (middle - 1); //Move down in the list
                }
                else
                {
                    low = (middle + 1); //Otherwise move up in the list

                }
                middle = (low + high) / 2; //Update the middle value
                probe++;
            }

            return 0; //If the number can't be found in the list then return nothing
        }

        private int LinearSearch(int valueToBeSearched)
        {
            int numOfEntries = lstIntegerValues.Items.Count;
            probe = 0;

            for (int i = 0; i < numOfEntries; i++)
            {
                int currentValueBeingChecked = Convert.ToInt32(lstIntegerValues.Items[i]);
                int listIndex = lstIntegerValues.Items.IndexOf(valueToBeSearched);

                if (currentValueBeingChecked == valueToBeSearched)
                {
                    return listIndex;
                    //Loops through list until the current value is the same as the value to be searched
                    //Then return the index
                }
                probe++;
            }
            return 0; //If the number can't be found return nothing
        }

        private void BubbleSort()
        {
            int numOfEntries = lstIntegerValues.Items.Count;
            int temp1, temp2;

            for (int j = 1; j < numOfEntries; j++)
            {
                for (int i = 0; i < (numOfEntries - j); i++)
                {
                    temp1 = Convert.ToInt32(lstIntegerValues.Items[i]);
                    temp2 = Convert.ToInt32(lstIntegerValues.Items[i + 1]);

                    Object temp;

                    if (temp1 > temp2)
                    {
                        temp = lstIntegerValues.Items[i];
                        lstIntegerValues.Items[i] = lstIntegerValues.Items[i + 1];
                        lstIntegerValues.Items[i + 1] = temp;
                    }
                }
            }
        }

        private void optUnsorted_CheckedChanged(object sender, EventArgs e)
        {
            if (optUnsorted.Checked == true)
            {
                optLinearSearch.Checked = true;
                optBinarySearch.Enabled = false;
            }
            else
            {
                optBinarySearch.Enabled = true;
            }
        }

        private void pictureOfBin_DragEnter(object sender, DragEventArgs e)
        {
            e.Effect = DragDropEffects.Copy;
        }

        private void lstIntegerValues_MouseDown(object sender, MouseEventArgs e)
        {
            int numOfEntries = lstIntegerValues.Items.Count;

            if (numOfEntries > 0)
            {
                if (lstIntegerValues.SelectedIndex != -1)
                {
                    lstIntegerValues.DoDragDrop(lstIntegerValues.SelectedItem, DragDropEffects.Copy);
                }
            }
        }

        private void pictureOfBin_DragDrop(object sender, DragEventArgs e)
        {
            lstIntegerValues.Items.Remove(lstIntegerValues.SelectedItem);

            Updating();
        }

        private int Insert(int valueToBeInserted)
        {
            int numOfEntries = lstIntegerValues.Items.Count;
            int listIndex = 0;
                
            for (listIndex = 0; listIndex < numOfEntries; listIndex++)
            {
                int currentValueBeingChecked = Convert.ToInt32(lstIntegerValues.Items[listIndex]);

                if (valueToBeInserted <= currentValueBeingChecked)
                {
                        break;
                }
            }
            return listIndex;
        }
    }
}
