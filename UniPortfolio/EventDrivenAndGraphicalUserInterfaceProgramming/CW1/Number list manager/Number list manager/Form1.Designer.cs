namespace Number_list_manager
{
    partial class frmNumberListManager
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
            this.picDragAndDropBin = new System.Windows.Forms.PictureBox();
            this.lstIntegerValues = new System.Windows.Forms.ListBox();
            this.lblNumberOfEntriesPermitted = new System.Windows.Forms.Label();
            this.lblMaximumValue = new System.Windows.Forms.Label();
            this.lblMinimumValue = new System.Windows.Forms.Label();
            this.lblLastEntry = new System.Windows.Forms.Label();
            this.lblFirstEntry = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.lblMaxNumOfEntiresAllowedLabel = new System.Windows.Forms.Label();
            this.lblMaximumValueLabel = new System.Windows.Forms.Label();
            this.lblMiniNumAllowedLabel = new System.Windows.Forms.Label();
            this.lblLastEntryLabel = new System.Windows.Forms.Label();
            this.lblFirstEntryLabel = new System.Windows.Forms.Label();
            this.lblIntegerCount = new System.Windows.Forms.Label();
            this.lblNumberOfEntries = new System.Windows.Forms.Label();
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnShuffle = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.btnInitialise = new System.Windows.Forms.Button();
            this.btnExit = new System.Windows.Forms.Button();
            this.lblTitle = new System.Windows.Forms.Label();
            this.grpSpecifySearch = new System.Windows.Forms.GroupBox();
            this.optBinarySearch = new System.Windows.Forms.RadioButton();
            this.optLinearSearch = new System.Windows.Forms.RadioButton();
            this.grpMannerOfDisplay = new System.Windows.Forms.GroupBox();
            this.optUnsorted = new System.Windows.Forms.RadioButton();
            this.optSorted = new System.Windows.Forms.RadioButton();
            this.txtSearchBox = new System.Windows.Forms.TextBox();
            this.txtInsertBox = new System.Windows.Forms.TextBox();
            this.btnSearch = new System.Windows.Forms.Button();
            this.btnInsert = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.picDragAndDropBin)).BeginInit();
            this.grpSpecifySearch.SuspendLayout();
            this.grpMannerOfDisplay.SuspendLayout();
            this.SuspendLayout();
            // 
            // picDragAndDropBin
            // 
            this.picDragAndDropBin.ImageLocation = "E:\\Computer Science - Year 2\\Event Driven and Graphical User Interface Programmin" +
    "g\\Assignments\\Assignment 1\\16020294\\Number list manager\\Bin.png";
            this.picDragAndDropBin.Location = new System.Drawing.Point(15, 305);
            this.picDragAndDropBin.Name = "picDragAndDropBin";
            this.picDragAndDropBin.Size = new System.Drawing.Size(70, 101);
            this.picDragAndDropBin.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.picDragAndDropBin.TabIndex = 75;
            this.picDragAndDropBin.TabStop = false;
            this.picDragAndDropBin.DragDrop += new System.Windows.Forms.DragEventHandler(this.pictureOfBin_DragDrop);
            this.picDragAndDropBin.DragEnter += new System.Windows.Forms.DragEventHandler(this.pictureOfBin_DragEnter);
            // 
            // lstIntegerValues
            // 
            this.lstIntegerValues.FormattingEnabled = true;
            this.lstIntegerValues.Location = new System.Drawing.Point(91, 219);
            this.lstIntegerValues.Name = "lstIntegerValues";
            this.lstIntegerValues.Size = new System.Drawing.Size(215, 212);
            this.lstIntegerValues.TabIndex = 74;
            this.lstIntegerValues.MouseDown += new System.Windows.Forms.MouseEventHandler(this.lstIntegerValues_MouseDown);
            // 
            // lblNumberOfEntriesPermitted
            // 
            this.lblNumberOfEntriesPermitted.AutoSize = true;
            this.lblNumberOfEntriesPermitted.Location = new System.Drawing.Point(502, 276);
            this.lblNumberOfEntriesPermitted.Name = "lblNumberOfEntriesPermitted";
            this.lblNumberOfEntriesPermitted.Size = new System.Drawing.Size(13, 13);
            this.lblNumberOfEntriesPermitted.TabIndex = 73;
            this.lblNumberOfEntriesPermitted.Text = "0";
            // 
            // lblMaximumValue
            // 
            this.lblMaximumValue.AutoSize = true;
            this.lblMaximumValue.Location = new System.Drawing.Point(502, 253);
            this.lblMaximumValue.Name = "lblMaximumValue";
            this.lblMaximumValue.Size = new System.Drawing.Size(13, 13);
            this.lblMaximumValue.TabIndex = 72;
            this.lblMaximumValue.Text = "0";
            // 
            // lblMinimumValue
            // 
            this.lblMinimumValue.AutoSize = true;
            this.lblMinimumValue.Location = new System.Drawing.Point(502, 230);
            this.lblMinimumValue.Name = "lblMinimumValue";
            this.lblMinimumValue.Size = new System.Drawing.Size(13, 13);
            this.lblMinimumValue.TabIndex = 71;
            this.lblMinimumValue.Text = "0";
            // 
            // lblLastEntry
            // 
            this.lblLastEntry.AutoSize = true;
            this.lblLastEntry.Location = new System.Drawing.Point(502, 208);
            this.lblLastEntry.Name = "lblLastEntry";
            this.lblLastEntry.Size = new System.Drawing.Size(13, 13);
            this.lblLastEntry.TabIndex = 70;
            this.lblLastEntry.Text = "0";
            // 
            // lblFirstEntry
            // 
            this.lblFirstEntry.AutoSize = true;
            this.lblFirstEntry.Location = new System.Drawing.Point(502, 187);
            this.lblFirstEntry.Name = "lblFirstEntry";
            this.lblFirstEntry.Size = new System.Drawing.Size(13, 13);
            this.lblFirstEntry.TabIndex = 69;
            this.lblFirstEntry.Text = "0";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(390, 142);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(59, 13);
            this.label7.TabIndex = 68;
            this.label7.Text = "Statistics";
            // 
            // lblMaxNumOfEntiresAllowedLabel
            // 
            this.lblMaxNumOfEntiresAllowedLabel.AutoSize = true;
            this.lblMaxNumOfEntiresAllowedLabel.Location = new System.Drawing.Point(312, 276);
            this.lblMaxNumOfEntiresAllowedLabel.Name = "lblMaxNumOfEntiresAllowedLabel";
            this.lblMaxNumOfEntiresAllowedLabel.Size = new System.Drawing.Size(184, 13);
            this.lblMaxNumOfEntiresAllowedLabel.TabIndex = 67;
            this.lblMaxNumOfEntiresAllowedLabel.Text = "Maximum number of entries permitted:";
            // 
            // lblMaximumValueLabel
            // 
            this.lblMaximumValueLabel.AutoSize = true;
            this.lblMaximumValueLabel.Location = new System.Drawing.Point(367, 253);
            this.lblMaximumValueLabel.Name = "lblMaximumValueLabel";
            this.lblMaximumValueLabel.Size = new System.Drawing.Size(129, 13);
            this.lblMaximumValueLabel.TabIndex = 66;
            this.lblMaximumValueLabel.Text = "Maximum value permitted:";
            // 
            // lblMiniNumAllowedLabel
            // 
            this.lblMiniNumAllowedLabel.AutoSize = true;
            this.lblMiniNumAllowedLabel.Location = new System.Drawing.Point(370, 230);
            this.lblMiniNumAllowedLabel.Name = "lblMiniNumAllowedLabel";
            this.lblMiniNumAllowedLabel.Size = new System.Drawing.Size(126, 13);
            this.lblMiniNumAllowedLabel.TabIndex = 65;
            this.lblMiniNumAllowedLabel.Text = "Minimum value permitted:";
            // 
            // lblLastEntryLabel
            // 
            this.lblLastEntryLabel.AutoSize = true;
            this.lblLastEntryLabel.Location = new System.Drawing.Point(384, 208);
            this.lblLastEntryLabel.Name = "lblLastEntryLabel";
            this.lblLastEntryLabel.Size = new System.Drawing.Size(112, 13);
            this.lblLastEntryLabel.TabIndex = 64;
            this.lblLastEntryLabel.Text = "Value of the last entry:";
            // 
            // lblFirstEntryLabel
            // 
            this.lblFirstEntryLabel.AutoSize = true;
            this.lblFirstEntryLabel.Location = new System.Drawing.Point(384, 187);
            this.lblFirstEntryLabel.Name = "lblFirstEntryLabel";
            this.lblFirstEntryLabel.Size = new System.Drawing.Size(112, 13);
            this.lblFirstEntryLabel.TabIndex = 63;
            this.lblFirstEntryLabel.Text = "Value of the first entry:";
            // 
            // lblIntegerCount
            // 
            this.lblIntegerCount.AutoSize = true;
            this.lblIntegerCount.Location = new System.Drawing.Point(502, 165);
            this.lblIntegerCount.Name = "lblIntegerCount";
            this.lblIntegerCount.Size = new System.Drawing.Size(13, 13);
            this.lblIntegerCount.TabIndex = 62;
            this.lblIntegerCount.Text = "0";
            // 
            // lblNumberOfEntries
            // 
            this.lblNumberOfEntries.AutoSize = true;
            this.lblNumberOfEntries.Location = new System.Drawing.Point(359, 165);
            this.lblNumberOfEntries.Name = "lblNumberOfEntries";
            this.lblNumberOfEntries.Size = new System.Drawing.Size(137, 13);
            this.lblNumberOfEntries.TabIndex = 61;
            this.lblNumberOfEntries.Text = "Number of entries in the list:";
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(10, 276);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(75, 23);
            this.btnDelete.TabIndex = 60;
            this.btnDelete.Text = "Delete";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // btnShuffle
            // 
            this.btnShuffle.Location = new System.Drawing.Point(10, 247);
            this.btnShuffle.Name = "btnShuffle";
            this.btnShuffle.Size = new System.Drawing.Size(75, 23);
            this.btnShuffle.TabIndex = 59;
            this.btnShuffle.Text = "Shuffle";
            this.btnShuffle.UseVisualStyleBackColor = true;
            this.btnShuffle.Click += new System.EventHandler(this.btnShuffle_Click);
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(10, 412);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(75, 23);
            this.btnClear.TabIndex = 58;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // btnInitialise
            // 
            this.btnInitialise.Location = new System.Drawing.Point(10, 218);
            this.btnInitialise.Name = "btnInitialise";
            this.btnInitialise.Size = new System.Drawing.Size(75, 23);
            this.btnInitialise.TabIndex = 57;
            this.btnInitialise.Text = "Initialise";
            this.btnInitialise.UseVisualStyleBackColor = true;
            this.btnInitialise.Click += new System.EventHandler(this.btnInitialise_Click);
            // 
            // btnExit
            // 
            this.btnExit.Location = new System.Drawing.Point(459, 412);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(75, 23);
            this.btnExit.TabIndex = 56;
            this.btnExit.Text = "Exit";
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // lblTitle
            // 
            this.lblTitle.AutoSize = true;
            this.lblTitle.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTitle.Location = new System.Drawing.Point(126, 10);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(275, 20);
            this.lblTitle.TabIndex = 55;
            this.lblTitle.Text = "Number List Manager programme";
            // 
            // grpSpecifySearch
            // 
            this.grpSpecifySearch.Controls.Add(this.optBinarySearch);
            this.grpSpecifySearch.Controls.Add(this.optLinearSearch);
            this.grpSpecifySearch.Location = new System.Drawing.Point(10, 165);
            this.grpSpecifySearch.Name = "grpSpecifySearch";
            this.grpSpecifySearch.Size = new System.Drawing.Size(297, 46);
            this.grpSpecifySearch.TabIndex = 54;
            this.grpSpecifySearch.TabStop = false;
            this.grpSpecifySearch.Text = "Specify the manner in which the list will be searched: ";
            // 
            // optBinarySearch
            // 
            this.optBinarySearch.AutoSize = true;
            this.optBinarySearch.Location = new System.Drawing.Point(188, 19);
            this.optBinarySearch.Name = "optBinarySearch";
            this.optBinarySearch.Size = new System.Drawing.Size(89, 17);
            this.optBinarySearch.TabIndex = 7;
            this.optBinarySearch.Text = "Binary search";
            this.optBinarySearch.UseVisualStyleBackColor = true;
            // 
            // optLinearSearch
            // 
            this.optLinearSearch.AutoSize = true;
            this.optLinearSearch.Checked = true;
            this.optLinearSearch.Location = new System.Drawing.Point(56, 19);
            this.optLinearSearch.Name = "optLinearSearch";
            this.optLinearSearch.Size = new System.Drawing.Size(89, 17);
            this.optLinearSearch.TabIndex = 6;
            this.optLinearSearch.TabStop = true;
            this.optLinearSearch.Text = "Linear search";
            this.optLinearSearch.UseVisualStyleBackColor = true;
            // 
            // grpMannerOfDisplay
            // 
            this.grpMannerOfDisplay.Controls.Add(this.optUnsorted);
            this.grpMannerOfDisplay.Controls.Add(this.optSorted);
            this.grpMannerOfDisplay.Location = new System.Drawing.Point(6, 83);
            this.grpMannerOfDisplay.Name = "grpMannerOfDisplay";
            this.grpMannerOfDisplay.Size = new System.Drawing.Size(301, 50);
            this.grpMannerOfDisplay.TabIndex = 53;
            this.grpMannerOfDisplay.TabStop = false;
            this.grpMannerOfDisplay.Text = "Manner in which to display the integer values:";
            // 
            // optUnsorted
            // 
            this.optUnsorted.AutoSize = true;
            this.optUnsorted.Checked = true;
            this.optUnsorted.Location = new System.Drawing.Point(60, 19);
            this.optUnsorted.Name = "optUnsorted";
            this.optUnsorted.Size = new System.Drawing.Size(68, 17);
            this.optUnsorted.TabIndex = 3;
            this.optUnsorted.TabStop = true;
            this.optUnsorted.Text = "Unsorted";
            this.optUnsorted.UseVisualStyleBackColor = true;
            this.optUnsorted.CheckedChanged += new System.EventHandler(this.optUnsorted_CheckedChanged);
            // 
            // optSorted
            // 
            this.optSorted.AutoSize = true;
            this.optSorted.Location = new System.Drawing.Point(192, 19);
            this.optSorted.Name = "optSorted";
            this.optSorted.Size = new System.Drawing.Size(56, 17);
            this.optSorted.TabIndex = 2;
            this.optSorted.Text = "Sorted";
            this.optSorted.UseVisualStyleBackColor = true;
            // 
            // txtSearchBox
            // 
            this.txtSearchBox.Location = new System.Drawing.Point(91, 139);
            this.txtSearchBox.Name = "txtSearchBox";
            this.txtSearchBox.Size = new System.Drawing.Size(216, 20);
            this.txtSearchBox.TabIndex = 52;
            // 
            // txtInsertBox
            // 
            this.txtInsertBox.Location = new System.Drawing.Point(91, 54);
            this.txtInsertBox.Name = "txtInsertBox";
            this.txtInsertBox.Size = new System.Drawing.Size(217, 20);
            this.txtInsertBox.TabIndex = 51;
            // 
            // btnSearch
            // 
            this.btnSearch.Location = new System.Drawing.Point(10, 136);
            this.btnSearch.Name = "btnSearch";
            this.btnSearch.Size = new System.Drawing.Size(75, 23);
            this.btnSearch.TabIndex = 50;
            this.btnSearch.Text = "Search";
            this.btnSearch.UseVisualStyleBackColor = true;
            this.btnSearch.Click += new System.EventHandler(this.btnSearch_Click);
            // 
            // btnInsert
            // 
            this.btnInsert.Location = new System.Drawing.Point(10, 54);
            this.btnInsert.Name = "btnInsert";
            this.btnInsert.Size = new System.Drawing.Size(75, 23);
            this.btnInsert.TabIndex = 49;
            this.btnInsert.Text = "Insert";
            this.btnInsert.UseVisualStyleBackColor = true;
            this.btnInsert.Click += new System.EventHandler(this.btnInsert_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(502, 322);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(13, 13);
            this.label1.TabIndex = 79;
            this.label1.Text = "0";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(502, 299);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(13, 13);
            this.label2.TabIndex = 78;
            this.label2.Text = "0";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(413, 322);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(83, 13);
            this.label3.TabIndex = 77;
            this.label3.Text = "Maximum value:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(416, 299);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(80, 13);
            this.label4.TabIndex = 76;
            this.label4.Text = "Minimum value:";
            // 
            // frmNumberListManager
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(546, 441);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.picDragAndDropBin);
            this.Controls.Add(this.lstIntegerValues);
            this.Controls.Add(this.lblNumberOfEntriesPermitted);
            this.Controls.Add(this.lblMaximumValue);
            this.Controls.Add(this.lblMinimumValue);
            this.Controls.Add(this.lblLastEntry);
            this.Controls.Add(this.lblFirstEntry);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.lblMaxNumOfEntiresAllowedLabel);
            this.Controls.Add(this.lblMaximumValueLabel);
            this.Controls.Add(this.lblMiniNumAllowedLabel);
            this.Controls.Add(this.lblLastEntryLabel);
            this.Controls.Add(this.lblFirstEntryLabel);
            this.Controls.Add(this.lblIntegerCount);
            this.Controls.Add(this.lblNumberOfEntries);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.btnShuffle);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.btnInitialise);
            this.Controls.Add(this.btnExit);
            this.Controls.Add(this.lblTitle);
            this.Controls.Add(this.grpSpecifySearch);
            this.Controls.Add(this.grpMannerOfDisplay);
            this.Controls.Add(this.txtSearchBox);
            this.Controls.Add(this.txtInsertBox);
            this.Controls.Add(this.btnSearch);
            this.Controls.Add(this.btnInsert);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "frmNumberListManager";
            this.Text = "Number list manager programme";
            this.Load += new System.EventHandler(this.frmNumberListManager_Load);
            ((System.ComponentModel.ISupportInitialize)(this.picDragAndDropBin)).EndInit();
            this.grpSpecifySearch.ResumeLayout(false);
            this.grpSpecifySearch.PerformLayout();
            this.grpMannerOfDisplay.ResumeLayout(false);
            this.grpMannerOfDisplay.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox picDragAndDropBin;
        private System.Windows.Forms.ListBox lstIntegerValues;
        private System.Windows.Forms.Label lblNumberOfEntriesPermitted;
        private System.Windows.Forms.Label lblMaximumValue;
        private System.Windows.Forms.Label lblMinimumValue;
        private System.Windows.Forms.Label lblLastEntry;
        private System.Windows.Forms.Label lblFirstEntry;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label lblMaxNumOfEntiresAllowedLabel;
        private System.Windows.Forms.Label lblMaximumValueLabel;
        private System.Windows.Forms.Label lblMiniNumAllowedLabel;
        private System.Windows.Forms.Label lblLastEntryLabel;
        private System.Windows.Forms.Label lblFirstEntryLabel;
        private System.Windows.Forms.Label lblIntegerCount;
        private System.Windows.Forms.Label lblNumberOfEntries;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Button btnShuffle;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Button btnInitialise;
        private System.Windows.Forms.Button btnExit;
        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.GroupBox grpSpecifySearch;
        private System.Windows.Forms.RadioButton optBinarySearch;
        private System.Windows.Forms.RadioButton optLinearSearch;
        private System.Windows.Forms.GroupBox grpMannerOfDisplay;
        private System.Windows.Forms.RadioButton optUnsorted;
        private System.Windows.Forms.RadioButton optSorted;
        private System.Windows.Forms.TextBox txtSearchBox;
        private System.Windows.Forms.TextBox txtInsertBox;
        private System.Windows.Forms.Button btnSearch;
        private System.Windows.Forms.Button btnInsert;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
    }
}

