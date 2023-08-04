package main

import (
	"fmt"
	"strings"
)

// Constants representing the format flags
const (
	NO_FLAG    = 0
	HASH_FLAG  = '#'
	SPACE_FLAG = ' '
	PLUS_FLAG  = '+'
)

// Function to handle format parsing and call appropriate print functions
func parseFormatType(format string, args ...interface{}) int {
	len := 0
	flag := NO_FLAG

	// Check for flag characters at the beginning of the format specifier
	if len(format) > 1 && strings.ContainsRune("# +", rune(format[0])) {
		flag = int(format[0])
		format = format[1:]
	}

	// Process different format specifiers
	switch format[0] {
	case '%':
		len += printChar('%')
	case 'c':
		len += printChar(args[0].(int))
	case 's':
		len += printStr(args[0].(string))
	case 'd', 'i':
		len += printNbr(args[0].(int), flag)
	case 'u':
		len += printUnsigned(args[0].(uint))
	case 'x', 'X':
		len += printHex(args[0].(uint), format[0], flag)
	case 'p':
		len += printPtr(args[0].(uint64))
	}

	return len
}

// Function to simulate ft_print_char
func printChar(c int) int {
	fmt.Printf("%c", c)
	return 1
}

// Function to simulate ft_print_str
func printStr(s string) int {
	fmt.Print(s)
	return len(s)
}

// Function to simulate ft_print_nbr
func printNbr(num int, flag int) int {
	if flag == PLUS_FLAG {
		fmt.Printf("+%d", num)
	} else {
		fmt.Print(num)
	}
	return len(fmt.Sprint(num))
}

// Function to simulate ft_print_unsigned
func printUnsigned(num uint) int {
	fmt.Print(num)
	return len(fmt.Sprint(num))
}

// Function to simulate ft_print_hex
func printHex(num uint, format byte, flag int) int {
	prefix := ""
	if flag == HASH_FLAG {
		if format == 'x' {
			prefix = "0x"
		} else {
			prefix = "0X"
		}
	}
	if format == 'x' {
		fmt.Print(prefix, fmt.Sprintf("%x", num))
	} else {
		fmt.Print(prefix, fmt.Sprintf("%X", num))
	}
	return len(fmt.Sprintf("%X", num))
}

// Function to simulate ft_print_ptr
func printPtr(ptr uint64) int {
	fmt.Print("0x", fmt.Sprintf("%X", ptr))
	return len(fmt.Sprintf("%X", ptr))
}

// Function to simulate ft_printf
func ftPrintf(format string, args ...interface{}) int {
	len := 0

	for i := 0; i < len(format); i++ {
		if format[i] == '%' {
			len += parseFormatType(format[i+1:], args[0])
			if format[i+1] == '#' || format[i+1] == ' ' || format[i+1] == '+' {
				i++
			}
		} else {
			len += printChar(int(format[i]))
		}
	}

	return len
}

func main() {
	ftPrintf("#X %#X\n", 442)
	fmt.Printf("#X %#X\n", 442)
}
