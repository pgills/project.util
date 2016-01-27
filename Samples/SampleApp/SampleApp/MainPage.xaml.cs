using ProjectUtil.UI.Composition;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Composition;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Hosting;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace SampleApp
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        
        public MainPage()
        {
            this.InitializeComponent();
            _compositor = ElementCompositionPreview.GetElementVisual(this).Compositor;
            _factory = CompositionImageFactory.CreateCompositionImageFactory(_compositor);

            _image = _factory.CreateImageFromUri(new Uri("ms-appx:///Assets/147Mint.png"));

            SpriteVisual sprite = _compositor.CreateSpriteVisual();
            sprite.Size = new Vector2(147, 147);
            sprite.Brush = _compositor.CreateSurfaceBrush(_image.Surface);

            ElementCompositionPreview.SetElementChildVisual(this, sprite);
        }

        private Compositor _compositor;
        private CompositionImageFactory _factory;
        private CompositionImage _image;
    }
}
