var LoginViewModel = require("./Login-view-model");
var loginViewModel = new LoginViewModel();
var frames = require("ui/frame");
var frameModule = require("tns-core-modules/ui/frame");
var dialogs = require("tns-core-modules/ui/dialogs");
const model = require('./model');

function pageLoaded(args) {
	var page = args.object;
	page.bindingContext = loginViewModel;
}

exports.iniciarSesion = function (args) {
	const pageSesion = args.object.page;
	const correoUsuario = pageSesion.getViewById("Correo");
	const contrasenaUsuario = pageSesion.getViewById("Contraseña");
	var xhttp = new XMLHttpRequest();
	console.log("Correo Electronico: " + correoUsuario.text + " Contraseña: " + contrasenaUsuario.text);
	if (correoUsuario.text == "" || contrasenaUsuario.text == "") {
		dialogs.alert({
			title: "Aviso!", message: "Hay campos vacios, debe llenar todos los campos",
			okButtonText: "ok"
		})
	} else {
		xhttp.onreadystatechange = function () {
			if (this.readyState == 4 && this.status == 200) {
				console.log("Respuesta: " + xhttp.responseText);
				if (xhttp.responseText == "Login correcto") {
					model.password = contrasenaUsuario.text;
					model.userName = correoUsuario.text;
					correoUsuario.text = "";
					contrasenaUsuario.text = "";
					var navegation = {
						moduleName: "home/home-page",
						transition: {
							name: "slideBottom"
						}
					};
					frames.topmost().navigate(navegation);
				} else if (xhttp.responseText == "Login incorrecto") {
					dialogs.alert({
						title: "¡Aviso!",
						message: "No se encontro el usuario",
						okButtonText: "Ok"
					})
				}
			}
		};
		xhttp.open("POST", "https://mywebfome.000webhostapp.com/loginGenerador.php", true);
		xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		xhttp.send("CorreoElectronico=" + correoUsuario.text + "&Contraseña=" + contrasenaUsuario.text);
	}
}

exports.pageLoaded = pageLoaded;