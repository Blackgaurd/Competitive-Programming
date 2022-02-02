// Segment Tree Test

package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

var _tk []string
var _iop int = 0

func su() int {
	r, _ := strconv.Atoi(_tk[_iop])
	_iop++
	return r
}
func sc() string {
	_iop++
	return _tk[_iop-1]
}

const MM int = 1e5 + 3

type range_ struct {
	l int
	r int
}
type node struct {
	g   int
	cnt int
}

var ranges [MM * 3]range_
var gcd_tree [MM * 3]node
var min_tree [MM * 3]int

func __gcd(a int, b int) int {
	if a%b == 0 {
		return b
	}
	return __gcd(b, a%b)
}
func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}
func combine(left node, right node) node {
	if left.g == right.g {
		return node{left.g, left.cnt + right.cnt}
	}
	gcd := __gcd(left.g, right.g)
	if gcd == left.g {
		return node{gcd, left.cnt}
	}
	if gcd == right.g {
		return node{gcd, right.cnt}
	}
	return node{gcd, 0}
}
func pushup(ind int) {
	min_tree[ind] = min(min_tree[ind*2], min_tree[ind*2+1])
	gcd_tree[ind] = combine(gcd_tree[ind*2], gcd_tree[ind*2+1])
}
func build(l int, r int, ind int) {
	ranges[ind].l = l
	ranges[ind].r = r
	if l == r {
		min_tree[ind] = su()
		gcd_tree[ind] = node{min_tree[ind], 1}
		return
	}
	var mid int = (l + r) / 2
	build(l, mid, ind*2)
	build(mid+1, r, ind*2+1)
	pushup(ind)
}
func update(pos int, val int, ind int) {
	if ranges[ind].l == ranges[ind].r {
		min_tree[ind] = val
		gcd_tree[ind] = node{val, 1}
		return
	}
	var mid int = (ranges[ind].l + ranges[ind].r) / 2
	if pos <= mid {
		update(pos, val, ind*2)
	} else {
		update(pos, val, ind*2+1)
	}
	pushup(ind)
}
func query_min(l int, r int, ind int) int {
	if ranges[ind].l == l && ranges[ind].r == r {
		return min_tree[ind]
	}
	var mid int = (ranges[ind].l + ranges[ind].r) / 2
	if r <= mid {
		return query_min(l, r, ind*2)
	} else if l > mid {
		return query_min(l, r, ind*2+1)
	}
	return min(query_min(l, mid, ind*2), query_min(mid+1, r, ind*2+1))
}
func query_gcd(l int, r int, ind int) node {
	if ranges[ind].l == l && ranges[ind].r == r {
		return gcd_tree[ind]
	}
	var mid int = (ranges[ind].l + ranges[ind].r) / 2
	if r <= mid {
		return query_gcd(l, r, ind*2)
	} else if l > mid {
		return query_gcd(l, r, ind*2+1)
	}
	return combine(query_gcd(l, mid, ind*2), query_gcd(mid+1, r, ind*2+1))
}

func main() {
	bytes, _ := ioutil.ReadAll(os.Stdin)
	_tk = strings.Fields(string(bytes))

	n, m := su(), su()
	build(1, n, 1)
	for m > 0 {
		m--
		c := sc()
		a, b := su(), su()
		if c == "C" {
			update(a, b, 1)
		} else if c == "M" {
			fmt.Println(query_min(a, b, 1))
		} else if c == "G" {
			fmt.Println(query_gcd(a, b, 1).g)
		} else {
			fmt.Println(query_gcd(a, b, 1).cnt)
		}
	}
}
