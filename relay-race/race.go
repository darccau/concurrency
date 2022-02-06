package main

import (
	"fmt"
	"time"
)

// simular corrida de revezamento
// 4 corredores
// o sedundo o terceiro e o quarto corredor nao podem correr ate receberem o bastao de seu atecessor
// utilizar o metodos sleep para simular o tempo de percorrimento do trajeto

func displayBanner() {
	fmt.Print("###################\n")
	fmt.Print("#    Start Race   #\n")
	fmt.Print("###################\n")
}

func run(runnersChannel chan int, runner int) {
	fmt.Printf("The runner %v start running\n", runner)
	time.Sleep(1 * time.Second)
	runner += 1

	fmt.Printf("The pipe has been passed to runner[%v]\n", runner)
	runnersChannel <- runner
}

func main() {
	var runner int = 1
	runnersChannel := make(chan int)

	displayBanner()

	go run(runnersChannel, runner)
	go run(runnersChannel, <-runnersChannel)
	go run(runnersChannel, <-runnersChannel)
	go run(runnersChannel, <-runnersChannel)
	fmt.Print("The race was ended")
}
