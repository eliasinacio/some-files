### CSS
~~~css
h1 {
  color: blue;
  background: gray;
  font-size: 14px;
}
~~~
___h1__ is a selector_

___{...}__ is a declaration._

___color, background, ...__ are properties._

___blue, gray, 14px__ are property values._



### Types of selectors:

___*__ is the Global selector._

___h1, p, div__ are Type/Element selectors._

___#box, #logo, #...__ is ID selector_

___.main, .btn, .x__ is Class selector_

_Others: __Attribute selector, Pseudo-class, Pseudo-element, more...___ 

## Numeric types and common units

### Types
___integer__ is a int number like __-10, 2, 100___

___number__ is a floot number like __-1.5, 0.2, 3.1415___

___dimension__ is a number with a unit like __90deg, 2s, 8px___

___percentage__ is a fraction of a number like __50%, 100%, 20%___

### Units
___length__ represents a distance value like __px, em, vw___

___angle__ represents a angle like __deg, rad, turn___

___time__ represents a time like __s, ms___

___resolution__ represents device resolution like __dpi___

### Absolute distances
___px__ is the most used and is a fixed distance_

### Relative distances
___em__ uses the parent element as a base_

___rem__ uses the root element(html) as a base_

___vw__ is __1%__ of the viewport width_

___vh__ is __1%__ of the viewport height_

___%__ is relative to the parent element_

#### Functions

___rgb(255, 255, 255)__ is a color calculation function_

___hsl()__ is a color calculation function_

___url('link')__ search something in a url_

___calc()__ calculates dimensions and values_

#### At-rules @

___@import__ include extern CSS_
___@media__ conditionals rules for devices_
___@font-face__ include extern fonts_
___@keyframes animationName__ create lkanimations_

#### Box-sizing 

~~~css
.box {
  box-sizing: border-box; /* priority to the border */
  box-sizing: content-box; /* priority to the content */
}
~~~

#### Display: block and inline

~~~css
.box {
  display: block; 
  /* one element for line */
  /* width and height work normally */
  /* margin, padding and border work normally */

  display: inline; 
  /* elements side by side */
  /* width and height not work */
  /* for margin, padding and border only horizontal values work */
}
~~~
