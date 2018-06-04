/*******************************************
 *
 * 2014 - Programación Web
 * Grado en Ingeniería Informática
 *
 * Ernesto Serrano <erseco@correo.ugr.es>
 *
 *******************************************
 *
 * Relación de ejercicios 2 - Javascript
 *
 *******************************************/

// Desarrollar una pagina web que capture 10 notas de alumnos y nos informe cuantos 
// tienen notas mayores o iguales a 7 y cuantos menores.
function ejercicio1() {

	// Atributos
	var mayores7 = "";
	var menores7 = "";

	// Recorremos los campos
	for (i=1;i<=10;i++) {

		// Obtenemos el valor del campo actual
        var valor = document.getElementById("campo"+i).value;

        // Comprobamos si es mayor que siete
        if (valor > 7) {
        	// Lo agregamos al acumulado de mayores
        	mayores7 += "Campo " + i + " \n";
        } else {
        	// Lo agregamos al acumulado de menores
        	menores7 += "Campo " + i + " \n";

        }

	}

	// Formateamos el resultado
	var resultado = "Mayores de 7:\n" + mayores7 + "\n" + "Menores de 7:\n" + menores7;

	// Mostramos el resultado
	alert(resultado);

}

// Desarrollar una pagina web en la que se ingresen un conjunto de 5 alturas de 
// personas por teclado y muestre la altura promedio de las personas.
function ejercicio2() {

	// Atributos
	var valor = 0;

	// Recorremos los campos
	for (i=1;i<=5;i++) {

		// Obtenemos el valor (usamos parseInt para convertir a entero)
        valor += parseInt(document.getElementById("altura"+i).value, 10);

	}

	// Dividimos entre 5 (la media)
	valor = valor / 5;

	// Formateamos el resultado
	var resultado = "El promedio es " + valor;

	// Mostramos el resultado
	alert(resultado);

}

// En una empresa trabajan 5 empleados cuyos sueldos oscilan entre $100 y $500, 
// desarrolle una pagina web que capture los sueldos que cobra cada empleado e 
// informe cuantos empleados cobran entre $100 y $300 y cuantos cobran mas de $300. 
// Ademas la pagina debera informar el importe que gasta la empresa en sueldos del personal.
function ejercicio3() {

	// Atributos
	var suma = 0;
	var menor300 = "";
	var mayor300 = "";

	// Recorremos los campos
	for (i=1;i<=5;i++) {

		// Obtenemos el valor (usamos parseInt para convertir a entero)
        var valor = parseInt(document.getElementById("sueldo"+i).value, 10);

        // Incrementamos el sumatorio
        suma += valor;

        // Comprobamos el sueldo para incrementar un numero u otro
        if (valor > 300) {
        	mayor300 += "Campo " + i + " \n";
        } else {
        	menor300 += "Campo " + i + " \n";

        }

	}

	// Formateamos el resultado
	var resultado = "Mayores de 300:\n" + mayor300 + "\n" + "Menores de 300:\n" + menor300 + "\n Total sueldos: " + suma;

	// Mostramos el resultado
	alert(resultado);

}

// Desarrollar una pagina web que tras pulsar un boton imprima 20 terminos de la serie 5 - 10 - 15 - 20, 
// etc. (No se ingresan valores por teclado)
function ejercicio4() {

	// Atributos
	var resultado = "";

	// Recorremos de 5 en 5
	for (i=5;i<=5*20;i+=5) {
    
    	// Agregamos el valor a la lista
        resultado += i + ", ";
	}

	// Mostramos el resultado en un elemento (en lugar de un alert)
	document.getElementById("ejercicio4").innerHTML = resultado;
}

function ejercicio5() {

	// Atributos
	var resultado = "";

	// Recorremos los campos
	for (i=10;i<=1500;i+=10) {

        resultado += i + ", ";

	}

	// Mostramos el resultado en un elemento (en lugar de un alert)
	document.getElementById("ejercicio5").innerHTML = resultado;
}

function ejercicio6() {

	var resultado = "";

	var sumLista1 = 0;
	var sumLista2 = 0;

	for (i=0;i<3;i++) {
        sumLista1 += parseInt(document.getElementById("lista1").options[i].value, 10);
	}
	for (i=0;i<3;i++) {
        sumLista2 += parseInt(document.getElementById("lista2").options[i].value, 10);
	}

	if (sumLista1 == sumLista2) {
		resultado = "Listas iguales";
	} else if (sumLista1 > sumLista2) {
		resultado = "Lista 1 mayor";
	} else {
		resultado = "Lista 2 mayor";
	}

	alert(resultado);
}

function ejercicio7() {

	var pares = "";
	var impares = "";

	for (i=1;i<=5;i++) {

        var valor = document.getElementById("par"+i).value;

        if (valor % 2 == 0) {
        	pares += "Campo " + i + " \n";
        } else {
        	impares += "Campo " + i + " \n";

        }

	}

	var resultado = "Pares:\n" + pares + "\n" + "Impares:\n" + impares;

	alert(resultado);

}

function ejercicio8_area() {

	var lado = parseInt(document.getElementById("lado").value, 10);
	var area = Math.pow(lado, 2);


	var resultado = "Area:\n" + area;

	alert(resultado);

}
function ejercicio8_perimetro() {

	var lado = parseInt(document.getElementById("lado").value, 10);
	var perimetro = 4 * lado;


	var resultado = "Perimetro:\n" + perimetro;

	alert(resultado);

}

function ejercicio9() {

	var numero = parseInt(document.getElementById("ejercicio9").value, 10);
	var digitos = numero.toString().length;

	var ventana = window.open ("ejercicios_ventana.html", "ventana");

	//Esperamos a que termine de cargar
	 ventana.onload = function() {
	 	ventana.document.getElementById("valor").innerHTML = digitos;
    }  

}

function ejercicio10() {

	var valor = 0;
	for (i=1;i<=3;i++) {

        valor += parseInt(document.getElementById("promedio"+i).value, 10);

	}

	valor = valor / 3;

	var ventana = window.open ("ejercicios_ventana.html", "ventana");

	//Esperamos a que termine de cargar
	 ventana.onload = function() {
	 	ventana.document.getElementById("valor").innerHTML = "Promedio: " + valor;
    }  
}

function ejercicio11() {

	var valor = 0;
	for (i=1;i<=5;i++) {

        valor += parseInt(window.prompt("Introduzca numero", 0), 10);

	}

	var ventana = window.open ("ejercicios_ventana.html", "ventana");

	//Esperamos a que termine de cargar
	 ventana.onload = function() {
	 	ventana.document.getElementById("valor").innerHTML = "Suma: " + valor;
    }  
}

function ejercicio12() {

	var fecha = new Date(Date.parse(document.getElementById("fecha").value));

	var mes = fecha.getMonth();

	var resultado;
	
	if (mes > 2 && mes < 7) {
		resultado = "2º Cuatrimestre";
	} else if (mes >= 7 && mes < 9) {
		resultado = "Vacaciones de verano";
	} else {
		resultado = "1er cuatrimestre";
	}

	alert(resultado)
}

function ejercicio13() {

    var boton = event.target;

    var resultado = "Boton: " + boton.textContent;

    alert(resultado);

}

function ejercicio14() {

    var password1 = document.getElementById("password1").value;
    var password2 = document.getElementById("password2").value;

    var contieneNumero = new RegExp("\d");
    var contieneMayuscula = new RegExp("[A-Z]");
	var contieneSimbolo = new RegExp("[^a-zA-Z\d\s:]");

    var resultado = "";

    if (password1 != password2) {
    	resultado = "Los passwords tienen que ser iguales"
    } else if (password1.length < 8) {
    	resultado = "El password tiene que tener 8 caracteres como mínimo"; 
    } else if (!contieneNumero.test(password1)) {
    	resultado = "El password debe contener un numero";
    } else if (!contieneMayuscula.test(password1)) {
    	resultado = "El password debe contener una mayúscula";
   	} else if (!contieneSimbolo.test(password1)) {
    	resultado = "El password debe contener un caracter no alfanumérico";
    }


    alert(resultado);

}



function ejercicio15() {

	var url;
	var random = Math.floor((Math.random()*3));

	if (random == 0) {
		url = "http://www.ugr.es";
	} else if (random == 1) {
		url = "http://decsai.ugr.es";
	} else {
		url = "http://etsiit.ugr.es"
	}

	window.open (url, "ventana");
 
}

function ejercicio16() {

	var options =  "height=" + (screen.height / 2) + ",width=" + screen.width;

	var ventana = window.open ("ejercicios_ventana.html", "ventana", options);

	//Esperamos a que termine de cargar
	 ventana.onload = function() {
	 	ventana.document.getElementById("valor").innerHTML = "Tamaño: " + options;
    }  

}

//Hacemos que al ejecutarse onload se llame al ejercicio17
//window.onload = ejercicio17();

function ejercicio17() {

	var cookies = "Cookies habilitadas: " + navigator.cookieEnabled;
	 
	 alert(cookies);

}


function suma () {
    this.primervalor = 0;
    this.segundovalor = 0;
    this.cargarvalor1 = function(valor) {
        this.primervalor = valor;
    };
    this.cargarvalor2 = function(valor) {
        this.segundovalor = valor;
    };
    this.retornarresultado = function() {
        return this.primervalor + this.segundovalor;
    };  

}

function ejercicio18() {

	var s=new suma(); 
	s.cargarvalor1(10);
	s.cargarvalor2(20);
	alert('La suma de los dos valores es:'+s.retornarresultado());

}

function persona(nombre, edad) {
	this.nombre = nombre;
	this.edad = edad;

	this.getNombre = function() {
		return this.nombre;
	};
	this.getEdad = function() {
		return this.edad;
	};
}

function ejercicio19() {

	var nombreMayores = "";
	var mayores = 0;
	var menores = 0;

	var personas = new Array();

	personas.push(new persona("Pepe", 16));
	personas.push(new persona("Jose", 20));

	personas.push(new persona("Enrique", 20));


	for (i=0;i<personas.length;i++) {

		if (personas[i].getEdad() >= 18) {
			nombreMayores += personas[i].getNombre() + "\n";
			mayores++;
		} else {
			menores++;
		}

	}


	var resultado = "Nombre mayores:\n" + nombreMayores + "Total mayores: " + mayores + "\nTotal menores: " + menores;
	alert(resultado);

}

function ejercicio20() {

	var dni = document.getElementById("ejercicio20").value;

	var numero
	var let
	var letra
	var expresion_regular_dni = /^\d{8}[a-zA-Z]$/;
 
	if(expresion_regular_dni.test (dni) == true){
		numero = dni.substr(0,dni.length-1);
		let = dni.substr(dni.length-1,1);
		numero = numero % 23;
		letra='TRWAGMYFPDXBNJZSQVHLCKET';
		letra=letra.substring(numero,numero+1);
	
		if (letra!=let) {
			alert('Dni erroneo, la letra del NIF no se corresponde');
		}else{
			alert('Dni correcto');
		}

	}else{

		alert('Dni erroneo, formato no válido');

	}


}