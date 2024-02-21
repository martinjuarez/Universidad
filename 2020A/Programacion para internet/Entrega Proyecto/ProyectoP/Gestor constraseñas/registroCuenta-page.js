var frameModule = require("tns-core-modules/ui/frame");
var RegistrocuentaViewModel = require("./registroCuenta-view-model");
var registrocuentaViewModel = new RegistrocuentaViewModel();
var dialogs = require("tns-core-modules/ui/dialogs");
var frames = require("ui/frame");
const model = require('./model');
var id = model.id;

function pageLoaded(args) {
	var page = args.object;
	page.bindingContext = registrocuentaViewModel;
}

exports.cancelar = function (args) {
	var navegation = {
		moduleName: "home/menu-page",
		transition: {
			name: "slideBottom"
		}
	};
	frames.topmost().navigate(navegation);
}

exports.enviar = function (args) {
	const page1 = args.object.page;
	const correo = page1.getViewById("correoElectronico")
	const cuenta = page1.getViewById("cuenta")
	const contrasena = page1.getViewById("contraseña")
	const confirmacion = page1.getViewById("reContraseña")
	var xhttp = new XMLHttpRequest();
	if (correo.text == "" || cuenta.text == "" || contrasena.text == "" || confirmacion.text == "") {
		dialogs.alert({
			title: "Aviso!", message: "Hay campos vacios, debe llenar todos los campos",
			okButtonText: "ok"
		})
	} else {
		if (contrasena.text == confirmacion.text) {
			xhttp.onreadystatechange = function () {
				if (this.readyState == 4 && this.status == 200) {
					console.log(xhttp.responseText);
					if (xhttp.responseText == "1") {
						dialogs.alert({
							title: "Aviso!", message: "Se inserto con exito",
							okButtonText: "ok"
						}).then(function () {
							correo.text = "";
							cuenta.text = "";
							contrasena.text = "";
							confirmacion.text = "";
						})
					} else if (xhttp.responseText == "0") {
						dialogs.alert({
							title: "Aviso!", message: "Fallo la insercion",
							okButtonText: "ok"
						}).then(function () {
							correo.text = "";
							cuenta.text = "";
							contrasena.text = "";
							confirmacion.text = "";
						})
					}
				}
			};
			xhttp.open("POST", "https://mywebfome.000webhostapp.com/altaCuenta.php", true);
			xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
			xhttp.send("Id=" + id + "&CorreoElectronico=" + correo.text + "&Cuenta=" + cuenta.text + "&Contrasena=" + contrasena.text);
		} else {
			dialogs.alert({
				title: "Aviso!", message: "Las contraseñas no coinciden",
				okButtonText: "ok"
			})
		}
	}
}

exports.pageLoaded = pageLoaded;