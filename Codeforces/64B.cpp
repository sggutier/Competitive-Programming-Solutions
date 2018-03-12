foreach opr {+ * - /} {
   set resultado [expr [join $numeros $opr]]
   puts "El resultado para el operador $opr es $resultado"
}
