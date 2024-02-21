import React from 'react';
import { BrowserRouter, Route, Switch } from 'react-router-dom';

import Login from '../Login';
import NotFound from '../NotFound';
import Home from '../Home';
import Register from '../Register';
import Prevention from '../Prevention';
import Symptom from '../Symptom';

const Routes = () => {
  return (
    <BrowserRouter>
      <Switch>
        <Route exact path="/login" component={Login} />
        <Route exact path="/home" component={Home} />
        <Route exact path="/register" component={Register} />
        <Route exact path="/symptom" component={Symptom} />
        <Route exact path="/prevention" component={Prevention} />
        <Route component={NotFound} />
      </Switch>
    </BrowserRouter>
  );
};

export default Routes;