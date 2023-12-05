package main

import "fmt"


// Creating an interface 
type cylinder_tank interface {  
    // Methods 
    Tarea() float64 
    Volume() float64 
} 
type myvalue struct { 
    radius float64 
    height float64 
}  
// Implementing methods of 
// the cylinder_tank interface 
func (m myvalue) Tarea() float64 { 
  
    return 2*m.radius*m.height + 
        2*3.14*m.radius*m.radius 
}   
func (m myvalue) Volume() float64 { 
  
    return 3.14 * m.radius * m.radius * m.height 
} 
// Main Method 
func main() { 
  
    // Accessing elements of 
    // the cylinder_tank interface 
    var t cylinder_tank 
    t = myvalue{13, 12} 
    fmt.Println("Surface Area of cylinder tank :", t.Tarea()) 
    fmt.Println("Volume of cylinder tank:", t.Volume()) 
} 