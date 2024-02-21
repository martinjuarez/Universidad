import { makeStyles } from '@material-ui/core/styles';


export default makeStyles((theme) => ({
  root: {
    backgroundColor: '#F8F8F8',
    height: '100vh',
    width: '100vw',
  },
  body: {
    display: 'flex',
  },
  modalContainer: {
    backgroundColor: '#FFFFFF',
    width: '400px',
    height: '300px',
    borderRadius: '10px',
    boxShadow: '0 4px 8px 0 rgba(0,0,0,0.2)',
    textAlign: 'center',
  },
  infoRoot: {
    margin: 'auto 20px auto 0px',
  },
  modalRoot: {
    display: 'flex',
    height: '100vh',
    alignItems: 'center',
    margin: 'auto',
  },
  modalTitle: {
    color: '#4B4279',
    fontWeight: 'bold',
    fontSize: '18px',
    margin: '20px 0px',
  },
  modalBody: {
    margin: '70px 0px',
    '& > div': {
      margin: '0px 5px',
      width: '80px',
      justifyContent: 'space-between',
      padding: '5px',
    }
  },
  map: {
    width: '700px',
    margin: 'auto 20px auto 20px',
  },
  mapLoaded: {
    textAlign: 'center'
  },
  tableContainer: {
    backgroundColor: '#E5E6E8',
    borderRadius: '4px',
    padding: '15px',
    width: '500px'
  },
  tableTitle: {
    color: '#E7004C',
    fontSize: '25px',
    fontWeight: 'bold',
    marginBottom: '10px'
  },
  tableHeader: {
    display: 'flex',
    justifyContent: 'space-between',
    backgroundColor: '#054583',
    padding: '5px',
  },
  tableHeaderItem: {
    color: '#FFFFFF',
    fontWeight: 'bold'
  },
  tableBodyCnf: {
    display: 'flex',
    backgroundColor: '#FDE5ED',
  },
  tableBodyItemCnfTitle: {
    backgroundColor: '#E7004C',
    color: '#FFFFFF',
    padding: '5px',
    fontWeight: 'bold',
    fontSize: '16px',
    width: '95px'
  },
  tableBodyItemCnfToday: {
    backgroundColor: '#FDE5ED',
    color: '#737682',
    padding: '5px',
    textAlign: 'center',
    fontWeight: 'bold',
    fontSize: '16x',
    width: '160px',
  },
  tableBodyItemCnfAll: {
    backgroundColor: '#FDE5ED',
    color: '#E70F5B',
    padding: '5px',
    textAlign: 'center',
    fontWeight: 'bold',
    fontSize: '16px',
    width: '200px'
  },
  tableBodySos: {
    display: 'flex',
    backgroundColor: '#FEF4E8',
  },
  tableBodyItemSosTitle: {
    backgroundColor: '#F7931E',
    color: '#FFFFFF',
    padding: '5px',
    fontWeight: 'bold',
    fontSize: '16px',
    width: '95px'
  },
  tableBodyItemSosToday: {
    backgroundColor: '#FEF4E8',
    color: '#737682',
    padding: '5px',
    textAlign: 'center',
    fontWeight: 'bold',
    fontSize: '16x',
    width: '160px',
  },
  tableBodyItemSosAll: {
    backgroundColor: '#FEF4E8',
    color: '#F7931E',
    padding: '5px',
    textAlign: 'center',
    fontWeight: 'bold',
    fontSize: '16px',
    width: '200px'
  },
  tableBodyDes: {
    display: 'flex',
    backgroundColor: '#E5F6FC',
  },
  tableBodyItemDesTitle: {
    backgroundColor: '#00A7E4',
    color: '#FFFFFF',
    padding: '5px',
    fontWeight: 'bold',
    fontSize: '16px',
    width: '95px'
  },
  tableBodyItemDesToday: {
    backgroundColor: '#E5F6FC',
    color: '#737682',
    padding: '5px',
    textAlign: 'center',
    fontWeight: 'bold',
    fontSize: '16x',
    width: '160px',
  },
  tableBodyItemDesAll: {
    backgroundColor: '#E5F6FC',
    color: '#12ACE6',
    padding: '5px',
    textAlign: 'center',
    fontWeight: 'bold',
    fontSize: '16px',
    width: '200px'
  },
  tableBodyDef: {
    display: 'flex',
    backgroundColor: '#FFFFFF',
  },
  tableBodyItemDefTitle: {
    backgroundColor: '#555353',
    color: '#FFFFFF',
    padding: '5px',
    fontWeight: 'bold',
    fontSize: '16px',
    width: '95px'
  },
  tableBodyItemDefToday: {
    backgroundColor: '#FFFFFF',
    color: '#737682',
    padding: '5px',
    textAlign: 'center',
    fontWeight: 'bold',
    fontSize: '16x',
    width: '160px',
  },
  tableBodyItemDefAll: {
    backgroundColor: '#FFFFFF',
    color: '#73706F',
    padding: '5px',
    textAlign: 'center',
    fontWeight: 'bold',
    fontSize: '16px',
    width: '200px'
  }
}));
