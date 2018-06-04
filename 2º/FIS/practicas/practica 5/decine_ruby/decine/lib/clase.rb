# 
# Ernesto Serrano <erseco@correo.ugr.es>
#
#  © Copyleft - All Wrongs Reserved

# Codigo para comprobar la función transform()


val = 2

valor = WRONG

if val % 2 == 0 #si el numero es par

  if  transform(val) == val*2
    valor = OK # la funcion es correcta
  else
    valor = WRONG # la funcion no funciona bien
  end
  
else #el numero es impar
  
  if val % 3 == 0 and transform(val) == val*3
    valor = OK # la funcion es correcta
  elsif val % 5 == 0 and transform(val) == val*5
    valor = OK # la funcion es correcta
  elsif tranform(val) == val
    valor = OK # la funcion es correcta
  else
    valor WRONG # la funcion no funciona bien
  end
  
  
  return valor

end