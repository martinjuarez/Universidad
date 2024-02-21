import React from 'react';

import HeadsetMicIcon from '@material-ui/icons/HeadsetMic';

import useStyles from './style';

const PhoneCovid = () => {
  const classes = useStyles();

  return (
    <div className={classes.root}>
      <div className={classes.img}>
        <HeadsetMicIcon color="primary" style={{ fontSize: 40 }} />
      </div>
      <div className={classes.text}>
        Linea COVID
      </div>
      <div>
        (33) 38-23-32-20
      </div>
    </div>
  );
};

export default PhoneCovid;
