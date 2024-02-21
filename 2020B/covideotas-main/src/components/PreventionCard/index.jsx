import React from 'react';
import { useHistory } from 'react-router-dom';

import distancing from '../../images/distancing.svg'
import ArrowForwardIcon from '@material-ui/icons/ArrowForward';

import useStyles from './style';

const PreventionCard = () => {
  const classes = useStyles();
  const history = useHistory();

  return (
    <div className={classes.root}
      onClick={() => history.push('/prevention')}
    >
      <div className={classes.img}>
        <img className={classes.img} alt="distancing" src={distancing} />
      </div>
      <div className={classes.info}>
        <div className={classes.infoTitle}>
          Prevención
        </div>
        <div className={classes.infoBody}>
          ¿Cómo protegerme del COVID 19?
        </div>
        <div className={classes.infoFooter}>
          <div className={classes.infoTitle}>
            Más info
        </div>
          <div className={classes.infoIcon}>
            <ArrowForwardIcon />
          </div>
        </div>
      </div>
    </div>
  );
};

export default PreventionCard;
