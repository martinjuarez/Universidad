var frameModule = require("tns-core-modules/ui/frame");
var CajafuerteViewModel = require("./cajaFuerte-view-model");
var cajafuerteViewModel = new CajafuerteViewModel();
const model = require('./model');
var frames = require("ui/frame");
var dialogs = require("tns-core-modules/ui/dialogs");
var cuenta = model.userName;
var contra = model.password;

function pageLoaded(args) {
	var page = args.object;
	page.bindingContext = cajafuerteViewModel;
}

function verificar(args) {
	var page0 = args.object.page;
	const codigo = page0.getViewById("cod");
	var xhttp = new XMLHttpRequest();
	if (codigo.text == "") {
		dialogs.alert({
			title: "Aviso!", message: "EL campo esta vacio",
			okButtonText: "ok"
		})
	} else {
		xhttp.onreadystatechange = function () {
			if (this.readyState == 4 && this.status == 200) {
				if (xhttp.responseText == "correcto") {
					var navegation = {
						moduleName: "home/cuenta-page",
						transition: {
							name: "slideBottom"
						}
					};
					frames.topmost().navigate(navegation);
				} else {
					dialogs.alert({
						title: "¡Aviso!",
						message: "Codigo erroneo",
						okButtonText: "Ok"
					})
				}
			}
		};
		xhttp.open("POST", "https://mywebfome.000webhostapp.com/verificarCodigo.php", true);
		xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		xhttp.send("CorreoElectronico=" + cuenta + "&Contraseña=" + contra + "&Codigo=" + codigo.text);
	}
}

exports.verificar = verificar;
exports.pageLoaded = pageLoaded;