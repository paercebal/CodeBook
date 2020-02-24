using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace CodeBook.ApplicationNet
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            this.LibVersion.Text = "Titi";
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            var m = new CodeBook.LibraryNet.Module();
            this.LibVersion.Text = m.GetVersion();
        }
    }
}
