import React, { useState } from 'react';
import { useHistory } from 'react-router-dom';

import TextField from '@material-ui/core/TextField';
import Button from '@material-ui/core/Button';

import { PhoneCovid, Header } from '../../components';

import { users } from '../../utils/data';

import useStyles from './style';

const Login = () => {
  const classes = useStyles();
  const history = useHistory();
  const [email, setEmail] = useState('');
  const [pass, setPass] = useState('');
  const [error, setError] = useState('');

  const handleLogin = () => {
    const user = users.find(_user => {
      return _user.email === email && _user.pass === pass;
    });
    if (user) {
      history.push('/home');
    } else {
      setError('Correo y/o contraseña incorrectos');
    }
  }

  return (
    <div>
      <Header />
      <div className={classes.root}>
        <div>
          <div className={classes.title}>
            Login
      </div>
          <div className={classes.input}>
            <TextField
              value={email}
              id="outlined-email-input"
              label="Correo electrónico"
              autoComplete="current-email"
              variant="outlined"
              onChange={(event) => setEmail(event.target.value)}
            />
          </div>
          <div className={classes.input}>
            <TextField
              value={pass}
              id="outlined-password-input"
              label="Contraseña"
              type="password"
              autoComplete="current-password"
              variant="outlined"
              onChange={(event) => setPass(event.target.value)}
            />
          </div>
          <div className={classes.error}>
            {error}
          </div>
          <div>
            <div className={classes.button}>
              <Button
                variant="contained"
                color="primary"
                onClick={() => handleLogin()}
              >
                Iniciar sesión
          </Button>
            </div>
            <div className={classes.button}>
              <Button
                variant="contained"
                color="primary"
                onClick={() => history.push('/register')}
              >
                Registro
          </Button>
            </div>
          </div>
        </div>
      </div>
      <div>
        <PhoneCovid />
      </div>
    </div>
  );
};

export default Login;
