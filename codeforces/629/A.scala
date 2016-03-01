object A {
  def main(args: Array[String]) {
    var arr = Array.ofDim[Char](128,128)
    var cnt = -1
    var n = 0
    for (ln <- io.Source.stdin.getLines) {
        if (cnt == -1) {
	    n = ln.trim.toInt
	}
        else {
	   for ( i <- 0 until ln.trim.length) {
		arr(cnt)(i) = ln(i)
	   } 
	}
	cnt = cnt + 1        
    }
    var res = 0
    for ( i <- 0 until n){
        var C = 0
	for (j<- 0 until n){
	    if(arr(i)(j)=='C'){
		C = C + 1
	    }
	}
        res = res + C*(C-1)/2
    }
    for ( j <- 0 until n){
        var C = 0
	for (i<- 0 until n){
	    if(arr(i)(j)=='C'){
		C = C + 1
	    }
	}
        res = res + C*(C-1)/2
    }
    println(res)
  }
}
