import { makeStyles } from '@material-ui/core/styles';

export default makeStyles((theme) => ({
  root: {
    backgroundColor: '#F8F8F8',
    width: '100vw',
    height: '100vh',
  },
  infoCard: {
    position: 'absolute',
    top: '100px',
  },
  infoContainer: {
    backgroundColor: '#FFFFFF',
    display: 'flex',
    width: '700px',
    padding: '20px'
  },
  imgLogo: {
    margin: '30px 20px 0px 20px',
    '& > img': {
      width: '100px',
      height: '100px',
    }
  },
  container: {
    display: 'flex',
    alignItems: 'center',
    justifyContent: 'center',
    height: '100%'
  },
  generalInfo: {
    fontSize: '12px',
    color: '#6D7278',
    margin: '20px 0px'
  },
  title: {
    fontSize: '16px',
    color: '#4B4279',
    fontWeight: 'bold',
    margin: '10px 0px'
  },
  list: {
    color: '#6D7278',
    fontSize: '14px',
    display: 'flex',
    alignItems: 'center',
    flexFlow: 'wrap',
    margin: '10px 0px',
  },
  dot: {
    borderRadius: '50%',
    width: '11px',
    height: '11px',
    background: '#FF4C4C',
    border: '3px solid #FFDDDD',
    margin: '10px',
  },
  listItem: {
    width: '500px',
  }
}));
