package main

import (
	"fmt" //fmt stands for format. Contains prinln, printf, scanf, etc.
	"time"
)

func main() {

	i := 2
	fmt.Print("Write ", i, " as ")
	switch i { // switch statements express conditionals across many branches.
	case 1: // case is like a break in C
		fmt.Println("one")
	case 2:
		fmt.Println("two")
	case 3:
		fmt.Println("three")
	}
	switch time.Now().Weekday() { // switch without an expression is an alternate way to express if/else logic.
	case time.Saturday, time.Sunday: // case expressions can be non-constants
		fmt.Println("It's the weekend")
	default: // default case is optional
		fmt.Println("It's a weekday")
	}
	t := time.Now()
	switch { // switch without an expression is an alternate way to express if/else logic.
	case t.Hour() < 12: // case expressions can be non-constants
		fmt.Println("It's before noon")
	default: // default case is optional
		fmt.Println("It's after noon")
	}
	whatAmI := func(i interface{}) {
		switch t := i.(type) {
		case bool:
			fmt.Println("I'm a bool")
		case int:
			fmt.Println("I'm an int")
		default:
			fmt.Printf("Don't know type %T\n", t)
		}
	}
	whatAmI(true)
	whatAmI(1)
	whatAmI("hey")
}

// The interface keyword in Go defines an interface type. An interface type specifies a
// set of methods that a concrete type must implement. It doesn't specify anything about
//the underlying concrete type.

// In the given code, i is an interface. The whatAmI function has a type switch that
// checks the underlying type of the interface and performs different actions depending
// on the type.

// // For example, if i holds an int, the whatAmI function will print "I'm an int". If it
// holds some other type, the default case will print "Don't know type %T\n", t" where
// %T is replaced by the type
