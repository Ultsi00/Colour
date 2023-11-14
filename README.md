# Colour  
Created on Linux Mint 21.2 Cinnamon. SDL2 framework for graphics.  
Purpose was to study the relation between Hue, Saturation and Value,  
whereas to shift from FP to OOP.

https://github.com/Ultsi00/Colour/assets/60548494/3a6a0764-4cd8-455d-9480-85c938b887e5
  
## Program explained  
Renders a colour wheel consisting of 12 hues:  
- 3 primary colours (RGB)
- 3 secondary colours
- 6 tertiary colours

All the rendering is done without the use of images, but by drawing (RGB) value at (x, y).    
Each hue is visualized in a segment, resulting in 12 segments forming a circle.  
Segments are drawn in arcs, increasing the arc radius in each iteration.  

Around the wheel, at orbit, circle-shaped hue selector can be re-positioned with user input.  
Selected hue value is transferred into a rectangle. The saturation of the selected hue  
can be modified with user input. Modified saturation is visualized in the drawn rectangle.  

Saturation can be gradually modified from maximum hue saturation (original hue value) to minimum  
saturation (255, 255, 255). Saturation changes can be reverted.  

### Saturation change implementation:  
The distance of the selected hue's R, G and B value to maximum saturation is calculated.  
From this distance, the increase/decrease steps are derived. Each increase/decrease  
in saturation modifies the R, G and B value proportionally to the components relative  
distance between initial value and maximum saturation. For example, if the fictional  
values were R(0), G(5), B(8), and the colour value min-max would be 0-10, one reduction  
in saturation towards (10, 10, 10) would result in R(1), G(5.5), B(8.2).  

## Input  
A = move selector counter-clockwise  
S = move selector clockwise  
Arrow_down = reduce Saturation  
Arrow_up = increase Saturation  
Arrow_left = reduce Value  
Arrow_right = increase Value  
ESC = exit  




### to-be implemented  
Value change member function. Similar logic to Saturation change, except the Hue value  
is manipulated between (0, 0, 0) - (R_initial, G_initial, B_initial), whereas in Saturation  
the range is (R_initial, G_initial, B_initial) - (255, 255, 255).  

