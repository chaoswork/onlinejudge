import scala.io.Source

object round_342_div2_A  {
def f(n:Long,a:Long,b:Long,c:Long) = {
    val x = (n-b)/(b-c)
    if (n >= b && a>(b-c)) (n-x*(b-c)-b+c)/a+1+x
    else n/a
}
def main(args: Array[String]){
  val in = Source.stdin.getLines()
  val n = in.next().toLong
  val a = in.next().toLong
  val b = in.next().toLong
  val c = in.next().toLong

  println(f(n,a,b,c))
}
}
