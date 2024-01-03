package main

func NumberOfBeams(bank []string) int {
	count := 0
	for i := 0; i < len(bank); i++ {
		row := bank[i]
		ones := countOnes(row)
		if ones > 0 {
			ni := getNearlyRowsWithOne(bank, i+1)
			if ni == -1 {
				break
			}
			nRow := bank[ni]
			nOnes := countOnes(nRow)
			count += ones * nOnes
		} else {
			continue
		}
	}
	return count
}

func countOnes(row string) int {
	count := 0
	for i := 0; i < len(row); i++ {
		if row[i] == '1' {
			count++
		}
	}
	return count
}

func getNearlyRowsWithOne(bank []string, index int) int {
	for i := index; i < len(bank); i++ {
		row := bank[i]
		ones := countOnes(row)
		if ones > 0 {
			return i
		}
	}
	return -1
}
