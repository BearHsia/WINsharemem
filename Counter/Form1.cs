using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Counter
{
    public partial class Form1 : Form
    {
        private int form_counter = 0;
        private bool enable = false;
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void FORM_timer_Tick(object sender, EventArgs e)
        {
            if (enable == false) return;
            if (form_counter < Int32.MaxValue)
                form_counter++;
            else
                form_counter = 0;
            return;
        }

        private void MMI_timer_Tick(object sender, EventArgs e)
        {
            label6.Text = form_counter.ToString();
        }

        private void init_button_Click(object sender, EventArgs e)
        {
            enable = true;
        }
    }
}
