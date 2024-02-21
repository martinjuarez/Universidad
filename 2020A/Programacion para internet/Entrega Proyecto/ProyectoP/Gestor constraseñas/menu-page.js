var frameModule = require("tns-core-modules/ui/frame");
var MenuViewModel = require("./menu-view-model");
var menuViewModel = new MenuViewModel();
var frames = require("ui/frame");
const model = require('./model');
var cuentas;
var corr = model.userName;
var counte = "Cuenta: " + corr;
var ide = model.id;
var identi = "Id: " + ide;

function pageLoaded(args) {
	var page = args.object;
	page.bindingContext = menuViewModel;
}

function sesion(args) {
	var page = args.object.page;
	var context = page.navigationContext;
	var xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function () {
		if (this.readyState == 4 && this.status == 200) {
			const response = xhttp.responseText;
			const items = response.split('*');
			cuentas = items.filter((item, index) => {
				const [id] = item.split('|');
				return Boolean(id);
			}).map(item => {
				const [cuenta, correo, contrasena] = item.split('|');
				return { cuenta, correo };
			});
			page.bindingContext = { ...context, cuentas, identi, counte };
		}
	};
	xhttp.open("POST", "https://mywebfome.000webhostapp.com/cuentas.php", true);
	xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	xhttp.send("ID=" + ide);
}

function onItemTap(args) {
	var index = args.index;
	model.cuentaCaja = cuentas[index].cuenta;
	model.correoCaja = cuentas[index].correo;
	var navegation = {
		moduleName: "home/cajaFuerte-page",
		transition: {
			name: "slideBottom"
		}
	};
	frames.topmost().navigate(navegation);
}

function registrarCount(args) {
	var navegation = {
		moduleName: "home/registroCuenta-page",
		transition: {
			name: "slideBottom"
		}
	};
	frames.topmost().navigate(navegation);
}

exports.registrarCount = registrarCount;
exports.onItemTap = onItemTap;
exports.sesion = sesion;
exports.pageLoaded = pageLoaded;