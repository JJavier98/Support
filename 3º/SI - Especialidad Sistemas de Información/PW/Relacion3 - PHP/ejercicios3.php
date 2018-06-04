<?php
/*******************************************
 *
 * 2014 - Programación Web
 * Grado en Ingeniería Informática
 *
 *******************************************
 *
 *	Relación de ejercicios 3 - PHP
 *
 *******************************************/
?>

<?php

/*
$valid_passwords = array ("mario" => "carbonell");
$valid_users = array_keys($valid_passwords);

$user = $_SERVER['PHP_AUTH_USER'];
$pass = $_SERVER['PHP_AUTH_PW'];

$validated = (in_array($user, $valid_users)) && ($pass == $valid_passwords[$user]);

if (!$validated) {
  header('WWW-Authenticate: Basic realm="My Realm"');
  header('HTTP/1.0 401 Unauthorized');
  die ("Not authorized");
}

// If arrives here, is a valid user.
echo "<p>Welcome $user.</p>";
echo "<p>Congratulation, you are into the system.</p>";
*/
?>
<h3>Ejercicio 1</h3>
<?php

	echo date("d, m \d\e Y");

?>

<!-- //////////////////////////////////////////////////////////////////////// -->
<h3>Ejercicio 2</h3>
<table border="1">
	<tr>
		<th>Columna 1</th>
		<th>Columna 2</th>
<?php
	foreach($_SERVER as $key => $value): 
		echo "<tr>";
		echo "	<td>".$key."</td>";
		echo "	<td>".$value."</td>";
		echo "</tr>";
	endforeach;
?>
</table>

<!-- //////////////////////////////////////////////////////////////////////// -->
<h3>Ejercicio 3</h3>
<?php

if (!empty($_GET) && isset($_GET["ejercicio3"])) {

	$pw = "";
	if ($_GET["asignatura"] != 1) {
		$pw = "No está matriculado en Programacion Web";
	}

	echo "<p>{$_GET["nombre"]} {$_GET["apellidos"]} ,  {$_GET["nacimiento"]} {$pw}</p>";

}

?>
<form method="get">
	<input type="hidden" name="ejercicio3" /><br />
	<input type="text" name="nombre" placeholder="Nombre" /><br />
	<input type="text" name="apellidos" placeholder="Apellidos" /><br />
	<input type="date" name="nacimiento" placeholder="Fecha nac" /><br />
	<select name="asignatura">
		<option value="1">Programacion Web</option>
		<option value="2">PDOO</option>
		<option value="3">Inteligencia Artificial</option>
		<option value="4">Sistemas Operativos</option>
		<option value="5">Fundamentos de Programacion</option>
	</select><br />
	<input type="submit" />

</form>

<!-- //////////////////////////////////////////////////////////////////////// -->
<h3>Ejercicio 4</h3>
<?php

if (!empty($_GET) && isset($_GET["ejercicio4"])) {

	echo "<p>{$_GET["nombre"]} {$_GET["apellidos"]}, {$_GET["dni"]} ,  {$_GET["nacimiento"]} - Asignatura: {$_GET["asignatura"]}</p>";

}

?>
<form method="get">
	<input type="hidden" name="ejercicio4" /><br />
	<input type="text" name="nombre" placeholder="Nombre" required /><br />
	<input type="text" name="apellidos" placeholder="Apellidos" required /><br />
	<input type="text" name="dni" placeholder="DNI" required pattern="(\d{8})([-]?)([A-Z]{1})" title="Formato DNI: 1234567Z"/><br />
	<input type="date" name="nacimiento" placeholder="Fecha nac" /><br />
	<select name="asignatura">
		<option>Programacion Web</option>
		<option>PDOO</option>
		<option>Inteligencia Artificial</option>
		<option>Sistemas Operativos</option>
		<option>Fundamentos de Programacion</option>
	</select><br />
	<input type="submit" />

</form>



