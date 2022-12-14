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
        private bool initialonce = false;
        public Form1()
        {
            InitializeComponent();
        }

        public sharedll.ShareMemoryCSharp shareMemoryCSharp_;

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void FORM_timer_Tick(object sender, EventArgs e)
        {
            if (shareMemoryCSharp_ == null)
                return;
            if (shareMemoryCSharp_.IsShareMemoryReady() == false)
                return;
            if (shareMemoryCSharp_.IsCountEnabled() == false)
                return;
            if (form_counter < Int32.MaxValue)
                form_counter++;
            else
                form_counter = 0;
            return;
        }

        private void MMI_timer_Tick(object sender, EventArgs e)
        {
            if (shareMemoryCSharp_ == null)
                return;
            if (shareMemoryCSharp_.IsShareMemoryReady() == false)
                return;
            if (shareMemoryCSharp_.IsCountEnabled() == false)
                return;

            label6.Text = form_counter.ToString();
            label5.Text = (shareMemoryCSharp_.InterruptCountValue()).ToString();
            label4.Text = (shareMemoryCSharp_.ForloopCountValue()).ToString();
        }

        private void init_button_Click(object sender, EventArgs e)
        {
            if (initialonce == true) return;
            initialonce = true;
            shareMemoryCSharp_ = new sharedll.ShareMemoryCSharp();
        }

        private void SW_button_Click(object sender, EventArgs e)
        {
            if (shareMemoryCSharp_ == null)
                return;
            if (shareMemoryCSharp_.IsShareMemoryReady() == false)
                return;
            if (shareMemoryCSharp_.IsCountEnabled() == true)
                shareMemoryCSharp_.DisableCount();
            else
                shareMemoryCSharp_.EnableCount();
        }
    }
}
