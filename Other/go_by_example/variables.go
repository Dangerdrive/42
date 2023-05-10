package main

import "fmt"

func main() {

	var a = "initial"
	fmt.Println(a)

	var b, c int = 1, 2
	fmt.Println(b, c)

	var e int //variables not initialized = 0.
	fmt.Println(e)

	f := "apple" // := declares and initializes a variable, inside the scope of a funcation.
	fmt.Println(f)
}
