package main

import "fmt"

func main() {

	if 7%2 == 0 {
		fmt.Println("7 is even")
	} else {
		fmt.Println("7 is odd")
	}

	if 8%4 == 0 {
		fmt.Println("8 is divisible by 4")
	}
	if num := -12; num < 0 { // in Go you can declare and initalize a variable, like you would have in a "for" loop in C
		fmt.Println(num, "is negative")
	} else if num < 10 {
		fmt.Println(num, "has 1 digit")
	} else {
		fmt.Println(num, "has multiple digits")
	}
}

// No need to use parentheses around conditions in Go, but braces are required.
//There is no ternary if in Go
