import React from 'react';
import { compose, withProps } from "recompose";
import { withScriptjs, withGoogleMap, GoogleMap, Marker, Polygon } from "react-google-maps";
import PropTypes from 'prop-types';

const LocationMap = compose(
  withProps({
    googleMapURL: "https://maps.googleapis.com/maps/api/js?key=AIzaSyDf-yIqxErTkbWzKhLox7nAANnrfDIY190",
    loadingElement: <div style={{ height: `100%` }} />,
    containerElement: <div style={{ height: `400px` }} />,
    mapElement: <div style={{ height: `100%` }} />,
  }),
  withScriptjs,
  withGoogleMap
)((props) =>
  <GoogleMap defaultZoom={15} center={props.position}>
    {props.position && <Marker noRedraw={true} position={props.position} />}
    {
      props.position && props.polygons.map((polygon, index) => {
        const { coords = [], color = '#000' } = polygon;
        return (<Polygon
          path={coords}
          key={index}
          options={{
            fillColor: color,
            fillOpacity: 0.4,
            strokeColor: color,
            strokeOpacity: 1,
            strokeWeight: 1
          }} />)
      })
    }
  </GoogleMap>
);

LocationMap.defaultProps = {
  polygons: [],
  position: { lat: 20.726854, lng: -103.372247 }
}

LocationMap.propTypes = {
  polygons: PropTypes.array,
  position: PropTypes.object,
};


export default LocationMap;
