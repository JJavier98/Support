<?php
session_start();
if(!$_POST){
  if(!isset($_SESSION["visita"])) {
    $_SESSION["visita"][] = time();
    $mensaje = "Bienvenido por primera vez a mi página web";
  } else {
    $mensaje = "Hola, su historial de visitas es: ";
    foreach($_SESSION["visita"] as $v){
      $mensaje = $mensaje."<br>".strftime("%d %B %Y a las %H:%M:%S", $v);
    }
    $_SESSION["visita"][] = time();
  }  
}else{
  unset($_SESSION["visita"]);
  $mensaje = "Todo ha sido borrado";
}
?>

<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta name="author" content="Francisco Vélez Ocaña">
  <title>Ejercicio 18. Sesiones</title>
</head>
<body>
  <?php echo $mensaje; ?>
  <form method="POST">
    <input type="submit" name="boton" value="Reiniciar contador de visitas">
  </form>
</body>
</html>
