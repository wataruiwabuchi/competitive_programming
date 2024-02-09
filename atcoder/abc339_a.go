package main

import (
	"fmt"
	"strings"
)
 
func main() {
	var S string
	fmt.Scan(&S)
 
	fmt.Println(S[strings.LastIndex(S, ".")+1:])
}