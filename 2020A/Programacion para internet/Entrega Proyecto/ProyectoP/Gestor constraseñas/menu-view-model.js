var observableModule = require("tns-core-modules/data/observable");

function MenuViewModel() {
	var viewModel = observableModule.fromObject({
    searchPhrase: "",
    onSearchSubmit: function(args) {
      let searchBar = args.object;
      console.log("You are searching for " + searchBar.text);
    },

    onButtonTap: function () {
      console.log("Button was pressed");
    },


	});

	return viewModel;
}

module.exports = MenuViewModel;