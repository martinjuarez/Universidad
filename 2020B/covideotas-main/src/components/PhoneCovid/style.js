import { makeStyles } from '@material-ui/core/styles';


export default makeStyles((theme) => ({
  root: {
    position: 'absolute',
    bottom: '0',
    backgroundColor: '#FC86B0',
    display: 'flex',
    alignItems: 'center',
    width: '350px',
    height: '100px',
    borderRadius: '10px',
    margin: '20px',
    fontWeight: 'bold',
    color: '#FFFFFF',
  },
  img: {
    margin: '0px 20px',
    '& > svg': {
      color: '#FFFFFF',
    }
  },
  text: {
    margin: '0px 5px',
    color: '#FFFFFF',
  },
}));
