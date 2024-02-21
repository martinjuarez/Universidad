import React from 'react';

import useStyles from './style';

const Header = () => {
  const classes = useStyles();

  return (
    <div className={classes.root}>
      <div className={classes.title}>
        En caso de presentar síntomas relacionados con COVID-19 llama al: 33 3823 3220
      </div>
    </div>
  );
};

export default Header;
