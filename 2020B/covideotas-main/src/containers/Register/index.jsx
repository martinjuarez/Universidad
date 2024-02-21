import React from 'react';
import { useHistory } from 'react-router-dom';

import TextField from '@material-ui/core/TextField';
import Button from '@material-ui/core/Button';

import doctorimg from '../../images/doctor1.svg'

import useStyles from './style';

const Register = () => {
  const classes = useStyles();
  const history = useHistory();

  return (
    <div className={classes.root}>
      <div className={classes.container}>
        <div className={classes.inputContainer}>
          <div className={classes.title}>
            Registrate en CovIdeotas Jalisco
          </div>
          <div className={classes.description}>
            Tu registro ayuda a obtener datos precisos sobre
            aglomeraciones en las zonas de la ciudad.
          </div>
          <div className={classes.input}>
            <TextField
              id="outlined-name-input"
              label="Tu nombre"
              autoComplete="current-name"
              variant="outlined"
            />
          </div>
          <div className={classes.input}>
            <TextField
              id="outlined-email-input"
              label="Correo electrónico"
              autoComplete="current-email"
              variant="outlined"
            />
          </div>
          <div className={classes.input}>
            <TextField
              id="outlined-email-input"
              label="Contraseña"
              type="password"
              autoComplete="current-password"
              variant="outlined"
            />
          </div>
          <div className={classes.input}>
            <TextField
              id="outlined-repeatPassword-input"
              label="Repetir contraseña"
              autoComplete="current-repeatPassword"
              type="password"
              variant="outlined"
            />
          </div>
          <div className={classes.button}>
            <Button
              variant="contained"
              color="primary"
              onClick={() => history.push('/login')}
            >
              Registro
          </Button>
          </div>
        </div>
        <div className={classes.imgContainer}>
          <img className={classes.img} alt="doctor" src={doctorimg} />
        </div>
      </div>
    </div>
  );
};

export default Register;