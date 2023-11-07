----
To-do:
----
Break hex value into rgb

How to apply multiply to Hex?

A   cursorpointer (e.g. hand) revolving around colour wheel
        ENTER to select colour at pointer
        Colourcode is copied into a Rectangle
        Two sliders to manipulate Rectangle colour, Saturation and Value
B   mousemovement/mouse click       do as last, interest was in colours

----
Ideas:
----
circle, in which colours are. circle divided into segments.
for example, can have 8 segments, each have a borderline from radian value.
each segments represents Hue.

***Saturation (=Chroma) (0,00 - 1,00):
the closer to origo, the lower the Saturation:
    Origo(low Saturation) == white, Perimeter (high Saturation) = 'full colour'
If Hue is (255, 0, 0) (now at Perimeter), moving closer to origo increases G and B equally towards 255.

***Value (0,00 - 1,00):
Multiplies the (Hue * Saturation): V(0,00) == black, V(1,00) == colour(Hue * Saturation)  

***Drawing
draw arcs based on radius and angle. Arc starts at radian 0 (East), moves counterclockwise


Child classes = different drawing geometry, arcs, lines...

----
Structure:
----


---
Formulas:
---
perimeter = 2 * pi * r

