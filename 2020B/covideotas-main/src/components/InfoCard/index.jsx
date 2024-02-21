import React from 'react';

import useStyles from './style';
import { generalInfo } from '../../utils/data';

const InfoCard = () => {
  const classes = useStyles();

  const { confirmed, discarded, suspects } = generalInfo;
  return (
    <div className={classes.root}>
      <div className={classes.cardDes}>
        <div className={classes.cardDesTitle}>
          Descartados
        </div>
        <div className={classes.cardNumberDesTitle}>
          {discarded}
        </div>
      </div>
      <div className={classes.cardSos}>
        <div className={classes.cardSosTitle}>
          En ubicación
        </div>
        <div className={classes.cardNumberSosTitle}>
          {suspects}
        </div>
      </div>
      <div className={classes.cardAct}>
        <div className={classes.cardActTitle}>
          Activos confirmados
        </div>
        <div className={classes.cardNumberActTitle}>
          {confirmed}
        </div>
      </div>
    </div>
  );
};

export default InfoCard;
