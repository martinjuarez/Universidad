var RegistroViewModel = require("./registro-view-model");
var registroViewModel = new RegistroViewModel();
var frames = require("ui/frame");
var frameModule = require("tns-core-modules/ui/frame");
var dialogs = require("tns-core-modules/ui/dialogs");

function pageLoaded(args) {
	var page = args.object;
	page.bindingContext = registroViewModel;
}

exports.cancelar = function (args) {
	var navegation = {
		moduleName: "home/home-page",
		transition: {
			name: "slideBottom"
		}
	};
	frames.topmost().navigate(navegation);
}

exports.enviar = function (args) {
	const page1 = args.object.page;
	const correo = page1.getViewById("correoElectronico")
	const nombre = page1.getViewById("nombre")
	const contrasena = page1.getViewById("contraseñaMaestra")
	const confirmacion = page1.getViewById("reContraseña")
	const pista = page1.getViewById("pista")
	var xhttp = new XMLHttpRequest();
	if (correo.text == "" || nombre.text == "" || contrasena.text == "" || confirmacion.text == "" || pista.text == "") {
		dialogs.alert({
			title: "Aviso!", message: "Hay campos vacios, debe llenar todos los campos",
			okButtonText: "ok"
		})
	} else {
		if (contrasena.text == confirmacion.text) {
			xhttp.onreadystatechange = function () {
				if (this.readyState == 4 && this.status == 200) {
					if (xhttp.responseText == "1") {
						dialogs.alert({
							title: "Aviso!", message: "Se inserto con exito",
							okButtonText: "ok"
						}).then(function () {
							correo.text = "";
							nombre.text = "";
							contrasena.text = "";
							confirmacion.text = "";
							pista.text = "";
						})
					} else if (xhttp.responseText == "0") {
						dialogs.alert({
							title: "Aviso!", message: "Fallo la insercion",
							okButtonText: "ok"
						}).then(function () {
							correo.text = "";
							nombre.text = "";
							confirmacion.text = "";
							pista.text = "";
						})
					}
				}
			};
			xhttp.open("GET", "https://mywebfome.000webhostapp.com/altasUsuario.php?CorreoElectronico=" + correo.text + "&Nombre=" + nombre.text + "&Contrasena=" + contrasena.text + "&Pista=" + pista.text, true);
			xhttp.send();
		} else {
			dialogs.alert({
				title: "Aviso!", message: "Las contraseñas no coinciden",
				okButtonText: "ok"
			})
		}
	}
}

exports.pageLoaded = pageLoaded;