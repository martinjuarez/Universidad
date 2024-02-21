var HomeViewModel = require("./home-view-model");
var homeViewModel = new HomeViewModel();
const fromObject = require("tns-core-modules/data/observable").fromObject;
const timerModule = require("tns-core-modules/timer");
let id;
const model = require('./model');
var cuenta = model.userName;
var contra = model.password;
var randNumber;

function pageLoaded(args) {
  var page = args.object;
  page.bindingContext = homeViewModel;
}

function generar(args) {
  const page = args.object.page;
  nuevoCodigo(args);
  const source = fromObject({
    res: randNumber
  });
  page.bindingContext = source;
}

function refresh(args) {
  const page = args.object.page;
  id = timerModule.setInterval(() => {
    nuevoCodigo(args);
    const source = fromObject({
      res: randNumber
    });
    page.bindingContext = source;
  }, 30000)
}

function nuevoCodigo(args) {
  const pageG = args.object.page;
  randNumber = Math.floor(Math.random() * 99999999);
  const correoUsuario = cuenta;
  const contrasenaUsuario = contra;
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      if (xhttp.responseText == "1") {
      }
    }
  };
  xhttp.open("POST", "https://mywebfome.000webhostapp.com/generadorCodigo.php", true);
  xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
  xhttp.send("Cuenta=" + correoUsuario + "&Contrasena=" + contrasenaUsuario + "&Codigo=" + randNumber);
}

exports.nuevoCodigo = nuevoCodigo;
exports.refresh = refresh;
exports.generar = generar;
exports.pageLoaded = pageLoaded;