import React from 'react';

import HomeIcon from '@material-ui/icons/Home';

import useStyles from './style';

const Warning = () => {
  const classes = useStyles();

  return (
    <div className={classes.root}>
      <div className={classes.icon}>
        <HomeIcon />
      </div>
      <div>
        <div className={classes.title}>
          Si tienes la posibilidad, quédate en casa.
      </div>
        <div className={classes.body}>
          Para prevenir el coronavirus la mejor acción es el distanciamiento social, por eso, si te cuidas tú, nos cuidas a todos.
      </div>
      </div>
    </div>
  );
};

export default Warning;
