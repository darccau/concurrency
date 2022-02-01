package main

import (
	"fmt"
	"time"
)

func run(runnersChannel chan int, runner int) {
	fmt.Printf("The runner %v start running\n", runner)
	time.Sleep(1 * time.Second)
	runner += 1

	if runner == 4 {
		fmt.Print("The race is over")
		return
	}

	runnersChannel <- runner
}

func main() {
	// runnersChannel := make(chan int, 4)

	fmt.Print("###################\n")
	fmt.Print("# The race beggin #\n")
	fmt.Print("###################\n")

	teams := make(map[string][4]int)

	teams["brasil"] = [4]int{1, 2, 3, 4}
	teams["chile"] = [4]int{1, 2, 3, 4}
	teams["Paraguai"] = [4]int{1, 2, 3, 4}
	teams["Argentina"] = [4]int{1, 2, 3, 4}
	fmt.Print(teams)

	// go run(runnersChannel, runner)
	// go run(runnersChannel, <-runnersChannel)
	// go run(runnersChannel, <-runnersChannel)
	// go run(runnersChannel, <-runnersChannel)

}
