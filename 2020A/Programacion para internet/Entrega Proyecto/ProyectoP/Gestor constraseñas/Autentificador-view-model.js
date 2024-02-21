var observableModule = require("tns-core-modules/data/observable");

function AutentificadorViewModel() {
	var viewModel = observableModule.fromObject({
    onButtonTap: function () {
      console.log("Button was pressed");
    },

    textFieldValue: "",


	});

	return viewModel;
}

module.exports = AutentificadorViewModel;
