package main

import (
	"fmt"
	"sync"
	"time"
)

func displayBanner() {
	fmt.Print("###################\n")
	fmt.Print("# The race beggin #\n")
	fmt.Print("###################\n")
}

func run(runnersChannel chan int, runner int) {
	// fmt.Printf("The runner [%v] from team [channel] start running\n", runner)
	time.Sleep(1 * time.Millisecond)

	runnersChannel <- runner
}

func prepareTeam(wg *sync.WaitGroup, teamName string, team [4]int, teamChannel chan int) {
	go run(teamChannel, team[0])
	<-teamChannel

	go run(teamChannel, team[1])
	<-teamChannel

	go run(teamChannel, team[2])
	<-teamChannel

	go run(teamChannel, team[3])
	<-teamChannel

	fmt.Printf("Team [%v] end the race\n", teamName)
	wg.Done()
}

func main() {

	displayBanner()

	var wg sync.WaitGroup
	wg.Add(4)

	brasilChannel := make(chan int)
	chileChannel := make(chan int)
	paraguaiChannel := make(chan int)
	argentinaChannel := make(chan int)

	teams := make(map[string][4]int)

	teams["brasil"] = [4]int{1, 2, 3, 4}
	teams["chile"] = [4]int{1, 2, 3, 4}
	teams["paraguai"] = [4]int{1, 2, 3, 4}
	teams["argentina"] = [4]int{1, 2, 3, 4}

	go prepareTeam(&wg, "brasil", teams["brasil"], brasilChannel)
	go prepareTeam(&wg, "chile", teams["chile"], chileChannel)
	go prepareTeam(&wg, "paraguai", teams["paraguai"], paraguaiChannel)
	go prepareTeam(&wg, "argentina", teams["argentina"], argentinaChannel)

	wg.Wait()
}
