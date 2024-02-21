var frameModule = require("tns-core-modules/ui/frame");
var CuentaViewModel = require("./cuenta-view-model");
var cuentaViewModel = new CuentaViewModel();
const fromObject = require("tns-core-modules/data/observable").fromObject;
const model = require('./model');
var dialogs = require("tns-core-modules/ui/dialogs");
var frames = require("ui/frame");
var cuentaM;
var correoM;

function pageLoaded(args) {
	var page = args.object;
	page.bindingContext = cuentaViewModel;
}

function refresh(args) {
	cuentaM = model.cuentaCaja;
	correoM = model.correoCaja;
}

function cuenta(args) {
	var page = args.object.page;
	var context = page.navigationContext;
	var xhttp = new XMLHttpRequest();
	refresh(args);
	xhttp.onreadystatechange = function () {
		if (this.readyState == 4 && this.status == 200) {
			var response = xhttp.responseText;
			var [cuenta, correo, contrasena] = response.split("|");
			if (xhttp.responseText != "Error") {
				page.bindingContext = { ...context, cuenta, correo, contrasena };
			}
		}
	};
	xhttp.open("POST", "https://mywebfome.000webhostapp.com/cuentaFinal.php", true);
	xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	xhttp.send("Cuenta=" + cuentaM + "&Correo=" + correoM);
}

function editar(args) {
	const page1 = args.object.page;
	const cuenta = page1.getViewById("Cuenta");
	const correo = page1.getViewById("Correo");
	const contrasena = page1.getViewById("Contraseña");
	var xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function () {
		if (this.readyState == 4 && this.status == 200) {
			if (xhttp.responseText == "1") {
				dialogs.alert({
					title: "¡Aviso!",
					message: "Usuario Editado",
					okButtonText: "Ok"
				})
				var navegation = {
					moduleName: "home/menu-page",
					transition: {
						name: "slideBottom"
					}
				};
				frames.topmost().navigate(navegation);
			}
		}
	};
	xhttp.open("POST", "https://mywebfome.000webhostapp.com/editar.php", true);
	xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	xhttp.send("Cuenta=" + cuenta.text + "&Correo=" + correo.text + "&Contraseña=" + contrasena.text + "&CuentaA=" + cuentaM + "&CorreoA=" + correoM);
}

function eliminar(args) {
	const page1 = args.object.page;
	const cuenta = page1.getViewById("Cuenta");
	const correo = page1.getViewById("Correo");
	const contrasena = page1.getViewById("Contraseña");
	var xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function () {
		if (this.readyState == 4 && this.status == 200) {
			if (xhttp.responseText == "1") {
				dialogs.alert({
					title: "¡Aviso!",
					message: "Usuario Eliminado",
					okButtonText: "Ok"
				})
				var navegation = {
					moduleName: "home/menu-page",
					transition: {
						name: "slideBottom"
					}
				};
				frames.topmost().navigate(navegation);
			}
		}
	};
	xhttp.open("POST", "https://mywebfome.000webhostapp.com/eliminar.php", true);
	xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	xhttp.send("Cuenta=" + cuenta.text + "&Correo=" + correo.text + "&Contraseña=" + contrasena.text);
}

exports.editar = editar;
exports.eliminar = eliminar;
exports.cuenta = cuenta;
exports.pageLoaded = pageLoaded;