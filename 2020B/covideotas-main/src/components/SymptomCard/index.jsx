import React from 'react';
import { useHistory } from 'react-router-dom';

import doctorimg from '../../images/doctor2.svg'
import ArrowForwardIcon from '@material-ui/icons/ArrowForward';

import useStyles from './style';

const SymptomCard = () => {
  const classes = useStyles();
  const history = useHistory();

  return (
    <div className={classes.root}
      onClick={() => history.push('/symptom')}
    >
      <div className={classes.img}>
        <img className={classes.img} alt="doctor2" src={doctorimg} />
      </div>
      <div className={classes.info}>
        <div className={classes.infoTitle}>
          Síntomas
        </div>
        <div className={classes.infoBody}>
          Conozca los síntomas del COVID 19
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

export default SymptomCard;
