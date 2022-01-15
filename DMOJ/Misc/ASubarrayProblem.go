// A Subarray Problem

package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"math"
	"os"
	"strconv"
	"strings"
)

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}
func max(a int, b int) int {
	if a < b {
		return b
	}
	return a
}
func main() {
	var bytes, _ = ioutil.ReadAll(bufio.NewReader(os.Stdin))
	tk := strings.Fields(string(bytes))

	const MM int = 1000003
	n, _ := strconv.Atoi(tk[0])
	var ind [MM]int
	for i := 1; i <= n; i++ {
		a, _ := strconv.Atoi(tk[i])
		ind[a] = i
	}
	l, r := math.MaxInt32, -1
	ans := 0
	for i := 1; i <= n; i++ {
		l = min(l, ind[i])
		r = max(r, ind[i])
		if r-l+1 == i {
			ans++
		}
	}
	fmt.Println(ans)
}
