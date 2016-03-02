import scala.io.Source

object round_342_div2_B {
    def main(args: Array[String]){
        val in = Source.stdin.getLines()
        val now = in.next() + "#"
        val old = in.next()

        println(now.split(old).length-1)
    }
}
