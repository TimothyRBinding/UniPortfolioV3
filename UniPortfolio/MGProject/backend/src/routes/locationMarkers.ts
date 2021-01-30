import * as express from 'express'
import locationMarkerController from '../controllers/locationMarkerController'
const router = express.Router()

router.get('/', locationMarkerController.getAllLocationMarkers)

export default router
