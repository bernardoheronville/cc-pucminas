fun main() {
  print("Digite o primeiro numero do intervalo: ")
  var num1 = readln().toInt()

  print("Digite o segundo numero do intervalo: ")
  var num2 = readln().toInt()

  for(i in num1..num2) {
    println(i)
  }

} 

