import React, { useState, useEffect } from 'react';
import moment from 'moment';
import mxLocale from "moment/locale/es-mx";

import Button from '@material-ui/core/Button';
import Chip from '@material-ui/core/Chip';
import DoneIcon from '@material-ui/icons/Done';
import CircularProgress from '@material-ui/core/CircularProgress';

import {
  PhoneCovid, Header, SymptomCard,
  PreventionCard, InfoCard, LocationMap,
  Warning,
} from '../../components';
import { locations, cases } from '../../utils/data';

import useStyles from './style';

const Home = () => {
  const [option, setOption] = useState('yes');
  const [item, setItem] = useState({});
  const [selectedItem, setSelectedItem] = useState('question');
  const classes = useStyles();

  useEffect(() => {
    const _item = locations[Math.floor(Math.random() * locations.length)] || {};
    setItem(_item);
  }, []);

  const handleSend = () => {
    if (option === 'yes') {
      setSelectedItem('thanks');
    } else {
      const random = Math.floor(Math.random() * locations.length);
      console.log(random)
      const _item = locations[random] || {};
      setItem({});
      setTimeout(() => { setItem(_item) }, 700);
    }
  };

  const handleRedirect = () => {
    setSelectedItem('table');
  };


  const { position = null, polygons = [] } = item;
  const { confirmados, defunciones, descartados, sospechosos } = cases
  const now = moment(new Date()).locale('es-mx').format('DD [de] MMMM [de] YYYY');
  return (
    <div className={classes.root}>
      <Header />
      <div className={classes.body}>
        <div className={classes.infoRoot}>
          <SymptomCard />
          <PreventionCard />
          <InfoCard />
        </div>

        {selectedItem === 'question' && (<div className={classes.modalRoot}>
          <div className={classes.modalContainer}>
            <div className={classes.modalTitle}>
              ¿Te encuentras en esta ubicación?
            </div>
            <div className={classes.modalBody}>
              <Chip
                label="Si"
                clickable
                onClick={() => setOption('yes')}
                color={option === 'yes' ? 'secondary' : ''}
                onDelete={() => { }}
                deleteIcon={option === 'yes' ? <DoneIcon /> : <DoneIcon style={{ display: 'none' }} />}
                variant="outlined"
              />
              <Chip
                label="No"
                clickable
                onClick={() => setOption('no')}
                color={option === 'no' ? 'secondary' : ''}
                onDelete={() => { }}
                deleteIcon={option === 'no' ? <DoneIcon /> : <DoneIcon style={{ display: 'none' }} />}
                variant="outlined"
              />
            </div>
            <div className={classes.button}>
              <Button
                variant="contained"
                color="secondary"
                onClick={() => handleSend()}
              >
                Enviar
          </Button>
            </div>
          </div>
        </div>)}
        {selectedItem === 'thanks' && (<div className={classes.modalRoot}>
          <div className={classes.modalContainer}>
            <div className={classes.modalBody}>
              Gracias por tu respuesta, tus datos nos ayudan a conocer el flujo de gente a tu alrededor, recuerda prestar atención a canales oficiales.
            </div>
            <div className={classes.button}>
              <Button
                variant="contained"
                color="secondary"
                onClick={() => handleRedirect()}
              >
                Enterado
          </Button>
            </div>
          </div>
        </div>
        )}
        {selectedItem === 'table' && (
          <div className={classes.modalRoot}>
            <div className={classes.tableContainer}>
              <div className={classes.tableTitle}>{now}</div>
              <div>
                <div className={classes.tableHeader}>
                  <div className={classes.tableHeaderItem}>Casos</div>
                  <div className={classes.tableHeaderItem}>{now}</div>
                  <div className={classes.tableHeaderItem} style={{ width: '160px' }}>Total acumulado</div>
                </div>
                <div className={classes.tableBodyCnf}>
                  <div className={classes.tableBodyItemCnfTitle}>Confirmados</div>
                  <div className={classes.tableBodyItemCnfToday}>{confirmados.today}</div>
                  <div className={classes.tableBodyItemCnfAll}>{confirmados.all}</div>
                </div>
                <div className={classes.tableBodySos}>
                  <div className={classes.tableBodyItemSosTitle}>Sospechosos</div>
                  <div className={classes.tableBodyItemSosToday}>{sospechosos.today}</div>
                  <div className={classes.tableBodyItemSosAll}>{sospechosos.all}</div>
                </div>
                <div className={classes.tableBodyDes}>
                  <div className={classes.tableBodyItemDesTitle}>Descartados</div>
                  <div className={classes.tableBodyItemDesToday}>{descartados.today}</div>
                  <div className={classes.tableBodyItemDesAll}>{descartados.all}</div>
                </div>
                <div className={classes.tableBodyDef}>
                  <div className={classes.tableBodyItemDefTitle}>Defunciones</div>
                  <div className={classes.tableBodyItemDefToday}>{defunciones.today}</div>
                  <div className={classes.tableBodyItemDefAll}>{defunciones.all}</div>
                </div>
              </div>
            </div>
          </div>
        )}
        <div className={classes.map}>
          {!position && (<div className={classes.mapLoaded}>
            <div>
              <CircularProgress color="secondary" />
            </div>
            <div>
              Obteniendo nueva ubicación
            </div>
          </div>)}
          {position && <LocationMap position={position} polygons={polygons} />}
        </div>
      </div>
      <div>
        <PhoneCovid />
        <Warning />
      </div>
    </div>
  );
};

export default Home;