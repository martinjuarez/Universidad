import { makeStyles } from '@material-ui/core/styles';


export default makeStyles((theme) => ({
  root: {
    backgroundColor: '#D8DDFF',
    display: 'flex',
    cursor: 'pointer',
    borderRadius: '15px',
    margin: '20px 0px 20px 20px',
  },
  info: {
    backgroundColor: '#DCFFF1',
    padding: '10px',
    width: '120px',
    borderRadius: '15px',
    marginLeft: '10px',
  },
  img: {
    width: '100px',
    height: '100px',
  },
  infoTitle: {
    color: '#14CB82',
    fontWeight: 'bold',
  },
  infoBody: {
    fontSize: '12px',
    margin: '5px 0px 10px 0px',
  },
  infoFooter: {
    display: 'flex',
    fontSize: '12px',
  },
  infoIcon: {
    margin: '0px 10px',
    '& > svg': {
      color: '#14CB82',
      fontSize: '15px',
    }
  },
}));
