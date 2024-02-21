var observableModule = require("tns-core-modules/data/observable");

function CuentaViewModel() {
	var viewModel = observableModule.fromObject({
    textFieldValue: "",

    onButtonTap: function () {
      console.log("Button was pressed");
    },


	});

	return viewModel;
}

module.exports = CuentaViewModel;
